#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int number = 4;
void *multi(void *input) {
//      sleep(1);
        int num = *(int*)input * 2;
        printf("Ausgabe Thread 1: %d\n", num);
}
void *add(void *input) {
        sleep(1);
        int num = *(int*)input + 2;
        printf("Ausgabe Thread 2: %d\n",num);
}
int main() {
        pthread_t p1, p2;
        pthread_create(&p1, NULL, multi, &number);
        pthread_create(&p2, NULL, add, &number);
        pthread_join(p1, NULL);
        pthread_join(p2, NULL);
}
