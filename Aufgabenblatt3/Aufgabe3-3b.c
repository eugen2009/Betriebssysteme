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

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int curThread = 0;
int timecount = 0;
void *createThread(void *input) {
	pthread_mutex_lock(&mutex);
	curThread++;  
	int actual = curThread;
        printf("Hello from thread No. %d!\n", curThread);
        pthread_mutex_unlock(&mutex);
	int tcount = 0;
        timecount += (*(int*) input);
	pthread_t p1, p2;
        sleep(*(int*)input);
        while(tcount < 2) {
		pthread_mutex_lock(&mutex);
		if(curThread < MAX_THREAD) {
			pthread_mutex_unlock(&mutex);
                        int num = (int) rand()%10;
			if (tcount == 0){
			         pthread_create(&p1, NULL, createThread, &num);
			}
			else {
				pthread_create(&p2, NULL, createThread, &num);
			}
		}
		pthread_mutex_unlock(&mutex);
                tcount++;
 	}
	//pthread_mutex_lock(&mutex);
	//if(curThread < MAX_THREAD){
	//	pthread_mutex_unlock(&mutex);
		pthread_join(p1, NULL);
	//}
	//pthread_mutex_unlock(&mutex);
	//pthread_mutex_lock(&mutex);
	//if(curThread < MAX_THREAD) {
	//	 pthread_mutex_unlock(&mutex);
		 pthread_join(p2, NULL);
	//}
	//pthread_mutex_unlock(&mutex);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	int start = 3;
	createThread(&start);
	printf("Die Threads haben zusammen %d Sekunden gewartet.\n", timecount);
}
