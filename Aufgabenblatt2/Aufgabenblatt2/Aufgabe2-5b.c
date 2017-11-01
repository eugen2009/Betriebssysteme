#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int pid = getpid();
	int pid2 = 0;
	int kidcount = 0;
	int status1;
	int status2;
	int status3;
	int i;
	int j;
	for (i = 0; i < 4; i++) {
		if (getpid() == pid) {
			fork();
			if (getppid() == pid) {
				printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
				sleep(5);
			}
			kidcount++;
		}
	}
	if (getpid() == pid){
		wait(&status1);
		printf("My PID is %d and I'm waiting for %d of my children to complete.\n", getpid(), kidcount);
	}
	kidcount = 0;
	for (i = 0; i < 2; i++) {
		if (getppid() == pid) {
			fork();
			if (getppid() != pid && getpid() != pid) {
				printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
				sleep(5);
			}
			kidcount++;
		}
	}
	if (getppid() == pid){
		wait(&status2);
		printf("My PID is %d and i'm waiting for %d of my children to complete.\n", getpid(), kidcount);
	} 
	kidcount = 0;
	if (getppid() != pid && getpid() != pid) pid2 = getpid();
	if(getpid() == pid2) {
		fork();
		if(getppid() == pid2){
			printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
			sleep(5);
		}
		kidcount++;
	}
	if(getpid() == pid2){
		wait(&status3);
		printf("My PID is %d and I'm waiting for %d of my children to complete.\n", getpid(), kidcount);
	}
	printf("My PID is: %d and I'm done.\n", getpid());
}
