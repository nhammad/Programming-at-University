#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


//getopt(int argc, char *const argv[], const char *optstring)
//as long as we can read an option, we can report a value
//when there are no options left, -1 is returned
//so we keep looping till we get -1

// "ls" are the 2 valid options: 3rd parameter

int main(int argc, char* argv[])
{
    int option;
    char ch;

    while((option = getopt(argc, argv, "ls")) != -1)
    {
        //system call
        if(option == 's')
        {
            ssize_t cnt;
            while((cnt = read(STDIN_FILENO, &ch, 1)) > 0)
            {
                cnt = write(STDOUT_FILENO, &ch, 1);

                if(cnt < 0)
                {
                    return EXIT_FAILURE;
                }
            }
		if(cnt < 0)
                {
                    return EXIT_FAILURE;
                }
        }

        //library calls
        else
        {
            while((ch = getc(stdin)) != EOF)
            {
                if(putc(ch, stdout) == EOF)
                {
                    return EXIT_FAILURE;
                }
            }
        }
    }
    if((option = getopt(argc, argv, "ls"))== -1)
    {
        return EXIT_FAILURE;
    }

    return 0;
}

//read:
//size_t read (int fd, void* buf, size_t cnt);
//fd: file descriptor/starting point
//buf: buffer to read data from/char in this case
//cnt: length of buffer (1 char so 1)
//Returns: How many bytes were actually read

//write:
//size_t write (int fd, void* buf, size_t cnt);
//for standard output, we always use 1 (STDOUT_FILENO) as the parameter
//buf: buffer to write data to
//Returns: How many bytes were actually written
