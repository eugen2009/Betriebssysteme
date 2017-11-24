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

int min(int a, int b) {
	if(a > b) return b;
	else return a;
}
struct input {
	int num;
	int cT;
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int divisor = 2;
int curThread = 0;
int timecount = 0;

void *createThread(void *input) {
	struct input *in = input;
	int actual = in->cT;
	printf("Hello from thread No. %d!\n", actual);
	pthread_t arr[in->num];
	int tcount = 0;
	int maxThreads = in->num;
	struct input threads[maxThreads];
	pthread_t p1, p2;
	int comp = min((int)floor(maxThreads/divisor), 16);
	while(tcount < maxThreads) {
		pthread_mutex_lock(&mutex);
		curThread++;
		struct input in;
		in.num = comp;
		printf("Debug\n");
		in.cT = curThread;
		threads[tcount] = in;
		pthread_create(&arr[tcount], NULL, createThread, &threads[tcount]);
		pthread_mutex_unlock(&mutex);
		tcount++;
 	}
	int i;
	for (i = 0; i < maxThreads; i++) pthread_join(arr[i], NULL);
        printf("Bye from thread No. %d!\n", actual);
}

int main() {
	struct input maxThreads;
	maxThreads.num = 26;
	maxThreads.cT = curThread;
	createThread(&maxThreads);
	printf("Insgesamt erzeugte Threads: %d\n", curThread);
}
