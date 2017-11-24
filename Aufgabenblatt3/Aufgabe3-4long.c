#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>

long min(long a, long b) {
	if(a > b) return b;
	else return a;
}
struct input {
	long num;
	long cT;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long divisor = 2;
long curThread = 0;
long timecount = 0;

void *createThread(void *input) {
	struct input *in = input;
	long actual = in->cT;
	printf("Hello from thread No. %d!\n", actual);
	pthread_t arr[in->num];
	long tcount = 0;
	long maxThreads = in->num;
	struct input threads[maxThreads];
	pthread_t p1, p2;
	long comp = min((long)floor(maxThreads/divisor), 16);
	while(tcount < maxThreads) {
		pthread_mutex_lock(&mutex);
		curThread++;
		struct input in;
		in.num = comp;
		in.cT = curThread;
		threads[tcount] = in;
		pthread_create(&arr[tcount], NULL, createThread, &threads[tcount]);
		pthread_mutex_unlock(&mutex);
		tcount++;
 	}
	long i;
	for (i = 0; i < maxThreads; i++) pthread_join(arr[i], NULL);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	struct input maxThreads;
	maxThreads.num = 25;
	maxThreads.cT = curThread;
	createThread(&maxThreads);
	printf("Insgesamt erzeugte Threads: %d\n", curThread);
}
