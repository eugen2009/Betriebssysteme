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
int curThread = 0;
void *createThread(void *input) {
        int actual = curThread;
        printf("Hello from thread No. %d!\n", actual);
        int tcount = 0;
        timecount += (*(int*) input);
        sleep(*(int*)input);
        while(tcount < 2) {
                if (curThread < MAX_THREAD) {
                        int num = (int) rand()%10;
                        pthread_t p1;
                        pthread_create(&p1, NULL, createThread, &num);
                        curThread++;
                        pthread_join(p1, NULL);
                }
                tcount++;
 }
        printf("Bye from thread No. %d!\n", actual);
        pthread_exit();
}
int main() {
int start = 3;
createThread(&start);
printf("Die Threads haben zusammen %d Sekunden gewartet.\n", timecount);
}
