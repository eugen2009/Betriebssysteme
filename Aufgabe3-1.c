#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void* multi() {
	num = num * 2;
}
void* add() {
	num = num + 2;
}
int main() {
	pthread_t threadid1;
	pthread_t* structp = &threadid1;
	int add() {
		num = num + 2;
	}
	pthread_create(structp, NULL, multi, NULL);
//	printf("Ausgabe: %d", num);
	pthread_create(structp, NULL, add, NULL);
	printf("Ausgabe: %d", num);
}

