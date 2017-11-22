#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>


struct input {
	int num;
	int cT;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int divisor = 2;
int curThread = 0;
int timecount = 0;

void *createThread(void *input) {
	printf("Hello from thread No. %d!\n", actual);
	*Thread timmey[*input];
	int tcount = 0;
	int maxThreads = input->num;
	pthread_t p1, p2;
	sleep(in->num);
	while(tcount < min(floor(maxThreads, divisor), 16)) {
		pthread_mutex_lock(&mutex);
		curThread++;
		struct input in;
		in.num = maxThreads;
		in.cT = curThread;
		pthread_create(array[x], NULL, createThread, &in);
		pthread_mutex_unlock(&mutex);
		tcount++;
 	}
	pthread_join(p1, NULL);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	maxThreads = 4;
	createThread(&maxThreads);
	printf("Die Threads haben zusammen %d Sekunden gewartet.\n", timecount);
}
