#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREAD 10000

struct input {
	int num;
	int cT;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
int curThread = 1;
int timecount = 0;

void *createThread(void *input) {
	struct input *in = input;
	int actual = in->cT;
        printf("Hello from thread No. %d!\n", actual);
	int tcount = 0;
	int counter = 0;
	pthread_mutex_lock(&mutex2);
        timecount += in->num;
	pthread_mutex_unlock(&mutex2);
	pthread_t p1, p2;
        sleep(in->num);
        while(tcount < 2) {
		pthread_mutex_lock(&mutex);
		if(curThread < MAX_THREAD) {
			curThread++;
			if (tcount == 0){
				struct input first;
                        	first.num = ((int) rand()%10)+1;
                        	first.cT = curThread;
			        pthread_create(&p1, NULL, createThread, &first);
				counter++;
			}
			else {
				struct input sec;
                        	sec.num = ((int) rand()%10)+1;
                        	sec.cT = curThread;
				pthread_create(&p2, NULL, createThread, &sec);
				counter++;
			}
		}
		pthread_mutex_unlock(&mutex);
                tcount++;
 	}
	if(counter > 0) pthread_join(p1, NULL);
	if(counter > 1) pthread_join(p2, NULL);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	struct input start;
	start.num = 0;
	start.cT = curThread;
	createThread(&start);
	printf("Die Threads haben zusammen %d Sekunden gewartet.\n", timecount);
}
