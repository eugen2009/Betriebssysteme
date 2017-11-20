#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREAD 10

struct input {
	int num;
	int cT;
};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int curThread = 0;
int timecount = 0;
void *createThread(void *input) {
	struct input *in = input;
	int actual = in->cT;
        printf("Hello from thread No. %d!\n", actual);
	int tcount = 0;
        timecount += in->num;
	pthread_t p1, p2;
        sleep(in->num);
        while(tcount < 2) {
		pthread_mutex_lock(&mutex);
		if(curThread < MAX_THREAD) {
			curThread++;  
			if (tcount == 0){
				struct input *i;
                        	i->num = (int) rand()%10;
                        	i->cT = curThread;
			        pthread_create(&p1, NULL, createThread, &i);
			}
			else {
				struct input *sec;
                        	sec->num = (int) rand()%10;
                        	sec->cT = curThread;
				pthread_create(&p2, NULL, createThread, &sec);
			}
		}
		pthread_mutex_unlock(&mutex);
                tcount++;
 	}
		 pthread_join(p1, NULL);
		 pthread_join(p2, NULL);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	struct input start;
	start.num = 3;
	start.cT = curThread;
	createThread(&start);
	printf("Die Threads haben zusammen %d Sekunden gewartet.\n", timecount);
}
