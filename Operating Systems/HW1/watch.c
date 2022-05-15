#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
     int option = getopt(argc, argv, "nbe");

     int status;

    //default sleep time if no value is given after -
     int delay = 2;

     char **c_argv = &argv[1];

     if (option == 'n')
     {
         //atoi = string to int
         //optind = option index
         //if we enter -n 5, we'll get 5 as delay, the val of n
         //wait for n seconds after each execution

          delay = atoi(argv[optind]);
          if (delay == 0)
          {
               perror("Time Value Shouldn't Be 0\n");
               exit(1);
          }
          else
          {
              	//child's argv array
              	//by +1, we read the command(eg date)
              	
               c_argv = &argv[optind + 1];
          }
     }

    //in this case, we just directly read the command
    //(eg date), which is on[2]

     else if (option == 'b' || option == 'e')
     {
          c_argv = &argv[2];
     }

    //printf("argv for child %s", c_argv[0]);

     while (1)
     {
          pid_t pid = fork();
          if (pid < 0)
          {
               printf("Unable to Fork()");
               exit(EXIT_FAILURE);
          }

         //child process
         //executing the date command from 
         //the child process array

          if (pid == 0)
          {
               execvp(c_argv[0], &c_argv[0]);
          }

         // parent process
          else
          {
              // wait for child process to complete
              //-1: for all child processes OR could use pid too
              //status = stores exit status of the child process
               waitpid(-1, &status, 0);
          }

         //status = -1;	//for checking other cases

          if (status != 0 && option == 'b')
          {
               printf("\a\n");
               fflush(stdout);	//emptying the buffer
          }
          else if (status != 0 && option == 'e')
          {
               exit(EXIT_FAILURE);
          }

         // delay between two executions in case of no errors
          sleep(delay);
     }
     return 0;
}

//int execvp(const char *file, char *const argv[]);
