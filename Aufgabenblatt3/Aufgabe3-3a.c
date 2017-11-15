#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAX_THREAD 10

int timecount = 0;
void *createThread(void *input, int curThread) {
        printf("Hello from thread No. %d!\n", curThread);
        int tcount = 0;
        timecount += (*(int*) input);
	pthread_t p1, p2;
        sleep(*(int*)input);
        while(tcount < 2) {
                if (curThread < MAX_THREAD) {
                        int num = (int) rand()%10;
			if (tcount == 0) pthread_create(&p1, NULL, createThread, &num, ++curThread);
			else pthread_create(&p2, NULL, createThread, &num);
                }
                tcount++;
 	}
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	int start = 3;
	createThread(&start);
	printf("Die Threads haben zusammen %d Sekunden gewartet.\n", timecount);
}
