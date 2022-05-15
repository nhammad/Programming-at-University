

int sem_init(sem_t, bar, person);
sem_t c;
sem_t d;
client_visit_bar(bar, person) {	
    
    if (detectives == 0) {
        while (clients > 0 && detectives == 0) {
            sem_wait(&c);
        }
    } else

    {
        sem_wait(&d);
        sem_wait(&c);
        person_t picked_detective = {
            DETECTIVE,
            0
        };

    }
    sem_post(&c);
    sem_post(&d);
}

detective_visit_bar(bar, person) {

    pthread_mutex_lock( & mutex);

    detectives++;

    if (clients == 0) {
        while (detectives > 0 && clients == 0) {
            sem_wait(&d);
        }
    } else {
        sem_wait(&d);

        while (clients) {
            sem_wait(&c);
            person_t picked_client = {
                CLIENT,
                clients
            };

        }

        while (clients) {
            sem_wait(&c);
        }

        sem_post(&c);
    }

    sem_wait(&d);
}

struct Semaphore{
int value;
Queue<process>q1;
Queue<process>q2;
}

client_visit_bar(bar_t *bar, person_t person)
{
    sem_wait(&c);
    q1.push();

    if(detectives == 0)
    {
        while (clients > 0 && detectives == 0) 
        {
            sem_wait(&c);
        }
    }
    else
    {
	sem_wait(&d);
	q2.pop();
        sem_wait(&c);
	q1.pop();
    }
    sem_post(&c);
    sem_post(&d);
}



detective_visit_bar(bar, person) {

    sem_wait(&c);
    q2.push();

    if (clients == 0) {
        while (detectives > 0 && clients == 0) {
            sem_wait(&d);
        }
    } else {
        sem_wait(&d);
	q2.pop();

        while (clients) {
            sem_wait(&c);
	    q1.pop();
            };

        }

        while (clients) {
            sem_wait(&c);
	    q1.pop();
        }

        sem_post(&c);
    }

    sem_post(&d);
}

