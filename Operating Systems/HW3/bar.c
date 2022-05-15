#define _REENTRANT
#define _DEFAULT_SOURCE
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <pthread.h>

#define CLIENT 0x01
#define DETECTIVE 0x02

typedef struct person {
    int type;
    int count;
} person_t;

typedef struct bar {
    int clients;
    int detectives;
    pthread_mutex_t mutex;
    pthread_cond_t  empty;
} bar_t;

static bar_t shared_bar = {
    .clients = 0,
    .detectives = 0,
    .mutex = PTHREAD_MUTEX_INITIALIZER,
    .empty = PTHREAD_COND_INITIALIZER,
};

static const char *progname = "bar";

static void
trace(char *event, bar_t bar, person_t person)
{
 fprintf(stderr, "\n %s:\t%d c\t%d d\t %c%d %s",
		    progname, bar.clients, bar.detectives, 
		    person.type==CLIENT ? 'c' : 'd', person.count , event);
}

static void
trace1(char *event, bar_t bar, person_t person)
{
 fprintf(stderr, "\n %s:\t%d c\t%d d\t %c%d %s",
		    progname, bar.clients, bar.detectives, 
		    person.type==CLIENT ? 'c' : 'd', person.count , event);
}

static void
client_visit_bar(bar_t *bar, person_t person)
{
    //printf("Client Type: %d\n",person.type);
    pthread_mutex_lock(&bar->mutex);
    
    trace1("entering", *bar, person);
    bar->clients++;

    if(shared_bar.detectives == 0)
    {
        //trace1("ordering drink", *bar, person);
        //client waits and orders a drink
        while (bar->clients > 0 && bar->detectives == 0) 
        {
            trace1("waiting", *bar, person);
            pthread_cond_wait(&bar->empty, &bar->mutex);
        }
    }
    else
    {
	//client picks the detective who entered the bar 
	//first and leaves the bar together with the chosen detective
        bar->detectives --;
        bar->clients --;
        person_t picked_detective = { DETECTIVE, 0};
        trace1("picking", *bar, picked_detective);
        sleep(1);
        trace1("leaving", *bar, person);
        trace1("leaving", *bar, picked_detective);
        pthread_cond_broadcast(&bar->empty);
	
    }
    pthread_mutex_unlock(&bar->mutex);
    
}



static void
detective_visit_bar(bar_t *bar, person_t person)
{
    //printf("Det Type: %d\n",person.type);
    pthread_mutex_lock(&bar->mutex);
    trace("entering", *bar, person);
    
    bar->detectives++;

    if(bar->clients == 0)
    {
        trace("talking to bartender", *bar, person);
        while (bar->detectives > 0 && bar->clients == 0) 
        {
            pthread_cond_wait(&bar->empty, &bar->mutex);
        }
    }
    else
    {
        bar->detectives --;
        int client_count = bar->clients;

	//detective picks up all clients and then leaves
        while(client_count)
        {
            client_count --;
            person_t picked_client = {CLIENT, client_count};
	//trace("picking client c%d", *bar, picked_client);

	fprintf(stderr, "\n %s:\t%d c\t%d d\t %c%d %s%d",
		    progname, bar->clients, bar->detectives, 
		    person.type==CLIENT ? 'c' : 'd', person.count , "picking up client c",client_count);
	}
//detective leaves
trace("leaving", *bar, person);

//now all clients that the detective picked up leave
while(bar->clients)
{
bar->clients--;
person_t picked_client = {CLIENT, bar->clients};

            trace("... waking up", *bar, picked_client);
	    //printf("...");
	    //trace(" waking up", *bar,picked_client);
            sleep(1);
            trace("leaving", *bar, picked_client);
            
        }

pthread_cond_broadcast(&bar->empty);
    }
    
    pthread_mutex_unlock(&bar->mutex);
}



static void
enjoy_life(person_t person)
{
    //trace("entering", shared_bar, person);
    while(1)
    {
        switch(person.type)
        {
	
        case CLIENT:
	//printf("CASE CLIENT\n");
            client_visit_bar(&shared_bar, person);
            break;
        
        case DETECTIVE:
        //printf("CASE DET\n");
            detective_visit_bar(&shared_bar, person);
            break;
        
            
        } 
	//random delay
        usleep(random() % 100000);
	if (shared_bar.clients == 0 && shared_bar.detectives == 0)
	{break;}
    }
}

static void*
thread_func(void *data)
{
    person_t person = *(person_t*)data;
    enjoy_life(person);
    return NULL;
}

static int
run(int clients, int detectives)
{
    int err, n = clients + detectives;
    //printf("VALUE:%d\n",n);
    pthread_t thread[n];
    
    person_t person;
    
    
    for (int i = 0; i < n; i++) {
        
    person.type = (i < clients) ? CLIENT : DETECTIVE;
    //printf("Type: %d\n",person.type);
    person.count = 0;
    
	err = pthread_create(&thread[i], NULL,
			     thread_func, &person);
        if (err) {
	    fprintf(stderr, "%s: %s(): unable to create thread %d: %s\n",
		    progname, "run", i, strerror(err));
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < n; i++) {
        if (thread[i]) {
	    err = pthread_join(thread[i], NULL);
	    if (err) {
		fprintf(stderr, "%s: %s(): unable to join thread %d: %s\n",
			progname, "run", i, strerror(err));
	    }
	}
    }

    return EXIT_SUCCESS;
}

int
main(int argc, char *argv[])
{
    int c, client_count = 1, detective_count = 1;
    
    while ((c = getopt(argc, argv, "c:d")) >= 0) {
        switch (c) {
        case 'c':

            if ((client_count = atoi(optarg)) <= 0) {
                fprintf(stderr, "Number of Clients Must be > 0\n");
                exit(EXIT_FAILURE);
            }
            //shared_bar.clients =  client_count;
            break;
            
        case 'd':
            if ((detective_count = atoi(optarg)) <= 0) {
                fprintf(stderr, "Number of Detectives Must be > 0\n");
                exit(EXIT_FAILURE);
            }
            //shared_bar.detectives = detective_count;
            break;
            
        case 'h':
            printf("Usage: %s [-c clients] [-d detectives] [-h help]\n", progname);
            exit(EXIT_SUCCESS);
        }
    }

    return run(client_count, detective_count);
return 0;
}


