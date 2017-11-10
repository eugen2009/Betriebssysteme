#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int num = 4;
void *multi(void *hello) {
	sleep(1);
	num = num * 2;
	printf("Ausgabe Thread 1: %d\n", num);
}
void *add(void *world) {
//	sleep(1);
	num = num + 2;
	printf("Ausgabe Thread 2: %d\n",num);
}
int main() {
	pthread_t p1, p2;
	pthread_create(&p1, NULL, multi, NULL);
	pthread_create(&p2, NULL, add, NULL);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
}
