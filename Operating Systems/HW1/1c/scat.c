#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sendfile.h>
#include <fcntl.h>

//getopt(int argc, char *const argv[], const char *optstring)
//as long as we can read an option, we can report a value
//when there are no options left, -1 is returned
//so we keep looping till we get -1

// "lsp" are the 3 valid options: 3rd parameter

int main(int argc, char * argv[]) {
    
    int option;
    char ch;

    while ((option = getopt(argc, argv, "lsp")) != -1) {
        
        //system call
        if (option == 's') {
            
            ssize_t cnt;
            while ((cnt = read(STDIN_FILENO, & ch, 1)) > 0) {
                cnt = write(STDOUT_FILENO, & ch, 1);

                if (cnt < 0) {
                    return EXIT_FAILURE;
                }
            }
            
            if (cnt < 0) {
                return EXIT_FAILURE;
            }
            
        } 
        
        else if (option == 'p') {
            ssize_t n;

	    //Linux System Call:
	    //sendfile(1,0,0,1) would also work
	    //but the question says that we have to 
	    //match the amount of bytes read/written 
            //by the C library copy loop
	    //we use a do while loop because at time of
	    //starting, n's value would be 0
            
            do {
                n = sendfile(1, 0, NULL, 4096);
            }
            
	//if it's the end of the file, it just
	//doesn't write
            while (n > 0);

            if (n < 0) {
                return EXIT_FAILURE;
            }

        }

        //library calls
        else {
            while ((ch = getc(stdin)) != EOF) {
                if (putc(ch, stdout) == EOF) {
                    return EXIT_FAILURE;
                }
            }
        }
    }
    
    if ((option = getopt(argc, argv, "ls")) == -1) {
        return EXIT_FAILURE;
    }

    return 0;
}

//read:
//size_t read (int fd, void* buf, size_t cnt);
//fd: file descriptor/starting point
//STDIN=0
//buf: buffer to read data from/char in this case
//cnt: length of buffer (1 char so 1)
//Returns: How many bytes were actually read

//write:
//size_t write (int fd, void* buf, size_t cnt);
//buf: buffer to write data to
//Returns: How many bytes were actually written

//sendfile()
//copies data between one file descriptor and another
//ssize_t sendfile(int out_fd, int in_fd, off_t *
//offset ", size_t" " count" );
//in_fd: file descriptor opened for reading
//out_fd should be a descriptor opened for writing.
//returns: number of bytes read
//4096: initial size required to store the meta-data 
//about files contained in that directory
