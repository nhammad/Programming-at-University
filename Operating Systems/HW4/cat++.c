/*
 * cat++/cat++.c
 *
 *	Copy multiple files to the standard output. Note that the
 *      special file name "-" is interpreted to mean stdin and may
 *      appear multiple times. This version checks for errors on the
 *      stdout stream and supports dynamically loadable transforms.
 */

#define _POSIX_C_SOURCE 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

static const char progname[] = "cat++";

typedef struct {
    void *handle;
    char *(*transform)(char *line);
} transform_t;

static char*
readline(FILE *f)
{
    size_t size = 0;
    size_t len  = 0;
    size_t last = 0;
    char * buf  = NULL;
    
    do {
	size += BUFSIZ;
	buf = realloc(buf, size);
	if (! buf) {
	    fprintf(stderr, "%s: memory allocation failure\n", progname);
	    exit(EXIT_FAILURE);
	}
	fgets(buf+last, size, f);
	len = strlen(buf);
	last = len - 1;
    } while (!feof(f) && buf[last] != '\n');

    buf[last] = '\0';
    return buf;
}

static int
cat(const char *filename, transform_t *transforms)
{
    int i;
    FILE *in;
    char *line;

    if (! filename || strcmp(filename, "-") == 0) {
	clearerr(stdin);
	in = stdin;
    } else {
	in = fopen(filename, "r");
	if (! in) {
	    perror(progname);
	    return -1;
	}
    }

    while (! feof(in)) {
	line = readline(in);
	if (line[0] != '\0' || !feof(in)) {
	    for (i = 0; transforms[i].handle; i++) {
		line = (*transforms[i].transform)(line);
	    }
	    puts(line);
	}
    }

    if (fflush(stdout) || ferror(stdout) || ferror(in)) {
	perror(progname);
	exit(EXIT_FAILURE);
    }
    
    if (in != stdin) {
	fclose(in);
    }

    return 0;
}

int
main(int argc, char *argv[])
{
    int c, t = 0;
    int code = EXIT_SUCCESS;
    char *error;

    transform_t transforms[argc];
    memset(transforms, 0, argc * sizeof(transform_t));

    while ((c = getopt(argc, argv, "hlv")) >= 0) {
	switch (c) {
	case 'h':
	    printf("Usage: %s [-h] [-l transform] [-v] files ... \n",
		   progname);
	    return EXIT_SUCCESS;
	case 'l':
	    (void) dlerror();
	    transforms[t].handle = dlopen(argv[optind++], RTLD_LAZY);
	    if (! transforms[t].handle) {
		fprintf(stderr, "%s: %s\n", progname, dlerror());
		return EXIT_FAILURE;
	    }
	    (void) dlerror();
	    transforms[t].transform = dlsym(transforms[t].handle, "transform");
	    if ((error = dlerror()) != NULL)  {
		fprintf(stderr, "%s: %s\n", progname, error);
		return EXIT_FAILURE;
	    }
	    t++;
	    break;
	case 'v':
	    printf("%s version 0.1.0\n", progname);
	    return EXIT_SUCCESS;
	default:
	    return EXIT_FAILURE;
	}
    }

    if (optind == argc) {
	if (cat(NULL, transforms) < 0) {
	    code = EXIT_FAILURE;
	}
    } else {
	for (; optind < argc; optind++) {
	    if (cat(argv[optind], transforms) < 0) {
		code = EXIT_FAILURE;
	    }
	}
    }

    for (t = 0; transforms[t].handle; t++) {
	(void) dlclose(transforms[t].handle);
    }

    return code;
}
