#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#define TOTAL 20

//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//void *(*start_routine) (void *), void *arg);

//returns: On success, pthread_create() returns 0; on error, it returns an error
//number, and the contents of *thread are undefined.

int def_persons = 100;
int def_flips = 1000;
char coins[] = {
        'O',
        'O',
        'O',
        'O',
        'O',
        'O',
        'O',
        'O',
        'O',
        'O',
        'X',
        'X',
        'X',
        'X',
        'X',
        'X',
        'X',
        'X',
        'X',
        'X'
};

//Code taken from source code directories provided by the Professor

/*
calloc: allocates the requested memory and returns a pointer to it. 
Unlike malloc, calloc sets allocated memory to zero.
n = num of elements
second arg = size of elements
*/

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static const char * progname = "pthread";

//second arg: return type (void), func(to run), arguments(for func)

static void run_threads(unsigned int n, void * ( * func)(void * )) 
{
        pthread_t * thread;
        int rc;

        thread = calloc(n, sizeof(pthread_t));
        if (!thread) 
        {
                fprintf(stderr, "%s: %s: %s\n", progname, __func__, strerror(errno));
                exit(EXIT_FAILURE);
        }

        for (int i = 0; i < n; i++) {
                rc = pthread_create( & thread[i], NULL, func, NULL);
                if (rc) 
                {
                        fprintf(stderr, "%s: %s: unable to create thread %d: %s\n",
                                progname, __func__, i, strerror(rc));
                }
        }

        for (int i = 0; i < n; i++) 
        {
                if (thread[i]) 
                {
                        (void) pthread_join(thread[i], NULL);
                }
        }

        (void) free(thread);
}

//flips N times all 20 coins

static void * method_one(void * data) {

	if(pthread_mutex_lock(&mutex) !=0 )
    	{
		perror("Locking Unsuccessful\n");
		exit(EXIT_FAILURE);
	}
        //printf("Coins: %s\n",coins);
        for (int i = 0; i < def_flips; i++) {

                for (int j = 0; j < TOTAL; j++) {

                        if (coins[j] == 'X') 
                        {
                                coins[j] = '0';
                        } else 
                        {
                                coins[j] = 'X';
                        }
                }
        }

        //printf("Coins: %s\n",coins);
        pthread_mutex_unlock( & mutex);

        return NULL;
}

// person obtains the lock, flips the 20 coins, 
//releases the lock, and then moves to the next iteration

static void * method_two(void * data) {

        for (int i = 0; i < def_flips; i++) {
                
		if(pthread_mutex_lock(&mutex) !=0 )
    		{
			perror("Locking Unsuccessful\n");
			exit(EXIT_FAILURE);
		}
                for (int j = 0; j < TOTAL; j++) {
                        if (coins[j] == 'X') 
                        {
                                coins[j] = '0';
                        } else 
                        {
                                coins[j] = 'X';
                        }
                }
                pthread_mutex_unlock( & mutex);
        }
        return NULL;
}

//separate lock for each coin
//a person obtains a lock for a coin, 
//flips the coin, and releases the lock 
//immediately after each coin flip

static void * method_three(void * data) {
        for (int i = 0; i < def_flips; i++) {
                for (int j = 0; j < TOTAL; j++) {
                       
			if(pthread_mutex_lock(&mutex) !=0 )
    			{
				perror("Locking Unsuccessful\n");
				exit(EXIT_FAILURE);
			}

                        if (coins[j] == 'X') 
                        {
                                coins[j] = '0';
                        } 
			
			else 
                        {
                                coins[j] = 'X';
                        }
                        pthread_mutex_unlock( & mutex);
                }
        }
        return NULL;
}

//code taken from the assignment sheet

static double timeit(int people, void * ( * proc)(void * )) {
        clock_t t1, t2;
        t1 = clock();
        run_threads(people, proc);
        t2 = clock();
        return ((double) t2 - (double) t1) / CLOCKS_PER_SEC * 1;
}

void printing_coins_start(char c) {
        if (c == 'g') 
        {
                printf("coins: %s (start - global lock)\n", coins);
        } 
        else if (c == 'i') 
        {
                printf("coins: %s (start - iteration lock)\n", coins);
        }
        else 
        {
                printf("coins: %s (start - coin lock)\n", coins);
        }
}

void printing_coins_end(char c) {
        if (c == 'g') 
        {
                printf("coins: %s (end - global lock)\n", coins);
        } 
        else if (c == 'i') 
        {
                printf("coins: %s (end - table lock)\n", coins);
        } 
        else 
        {
                        printf("coins: %s (end - coin lock)\n", coins);
        }
}

void printing_details(int def_persons, int def_flips, double time) {
        printf("%d threads x %d flips: %0.3lf ms\n \n", def_persons, def_flips, time);
}

int main(int argc, char * argv[]) {

        int option;
        int num_people, num_flips;

        pthread_mutex_init( & mutex, NULL);

        while ((option = getopt(argc, argv, "p:n:")) != -1) {

                if (option == 'p') {

                        //atoi returns 0 if operation is unsucessful
                        //atoi converts string to int

                        num_people = atoi(optarg);
                        if (num_people <= 0) 
                        {
                                perror("Inavlid Value of P (Number of People).\n");
                                exit(1);
                        }
                        def_persons = num_people;

                } else if (option == 'n') 
                {

                        num_flips = atoi(optarg);
                        if (num_flips <= 0) 
                        {
                                perror("Invalid Value of N (Number of Flips)\n");
                                exit(1);
                        }
                        def_flips = num_flips;
                } 
                else 
                {
                        printf("Invalid Option\n");
                        exit(1);
                }
        }

        double timeA, timeB, timeC;

        printing_coins_start('g');
        timeA = timeit(def_persons, method_one);
        printing_coins_end('g');
        printing_details(def_persons, def_flips, timeA);

        printing_coins_start('i');
        timeB = timeit(def_persons, method_two);
        printing_coins_end('i');
        printing_details(def_persons, def_flips, timeB);

        printing_coins_start('c');
        timeC = timeit(def_persons, method_three);
        printing_coins_end('c');
        printing_details(def_persons, def_flips, timeC);

        return 0;
}
