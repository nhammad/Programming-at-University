/*
JTSK-320112
a6_p5.c
Neeha Hammad
n.hammad@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int i, elem, read, written, mark=0;
    char content[64];
    char filename[50];
    FILE *fnew;     //output file
    FILE *finput;
    fnew = fopen("output.txt", "wb");
    int sizeof_file, member;
    for (i=0; i<n; i++)
    {
        //reading word by word
        fgets(filename, sizeof(filename), stdin);
        //changing new line into end of line
        filename[strlen(filename)-1] = '\0';
        finput = fopen(filename, "rb");
        fseek(finput, 0L, SEEK_END);
        //ftell: returns current position in long value
        sizeof_file = ftell(finput);
        fseek(finput, 0L, SEEK_SET);
        do
        {
		
	    if (sizeof_file > sizeof(content))
	    {
		member = sizeof(content);
	    }
	    else
	    {
		member = sizeof_file;
            }

            read = fread(content, 1, member, finput); //amount of read
            if(read == member)
                written = fwrite(content, 1, member, fnew);
            else
            {
                printf("Can't read the input file\n");
                exit(1);
            }
            if(written != read)
            {
                printf("Unable to concatenate\n");//output
                exit(1);
            }
            if(sizeof_file < sizeof(content))
            {
                mark=1;
            }
            else
                sizeof_file = sizeof_file - sizeof(content);
        }
        while(mark != 1);
        {
            fclose(finput);
        }
    }
    fclose(fnew);
    fnew = fopen("output.txt", "rb");
    //reading character by character until the end of file
    //to display results
    printf("Concating the content of %d files ...\n",n);
    printf("The result is:\n");
    while((elem=getc(fnew))!= EOF )
    {
        putchar(elem);
    }
    printf("The result was written into output.txt\n");
    fclose(fnew);//close file
    return 0;
}

//fseek(finput, 0L, SEEK_END);
//finput is a file pointer, points to file via fopen()
//offset (0L) is how far to move (in bytes) from the reference point
//SEEK_END specifies the reference point (end of file)

//ftell() returns current position of file pointer as a long value

//fread syntax:
//size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
//total number of elements successfully read are returned
//works without size_t as well, as in my case
//size_t is an object which is an integral data type
