#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int pid = getpid();
	int pid2 = 0;
	int kidcount;
	int i;
	for (i = 0; i < 4; i++) {
		if (getpid() == pid) {
			fork();
			printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
			sleep(1);
			kidcount++;
		}
	}
	printf("%d\n", kidcount);
	kidcount = 0;
	for (i = 0; i < 2; i++) {
		if(getppid() == pid) {
			fork();
			printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
			sleep(1);
			kidcount++;
		}
	}
	if (getppid() != pid) pid2 = getpid();
	printf("%d\n", kidcount);
	kidcount = 0;
	if(getpid() == pid2) {
		fork();
	//	pid = getpid();
		printf("Hello, my PID is: %d, my parent's PID is %d\n", getpid(), getppid());
		sleep(1);
		kidcount++;
	}
	if (getpid() == pid) {
		int status;
		if (getpid() == pid) printf("I'm the parent (with the PID: %d) and im waiting for one of my children to complete\n", getpid());
		wait(&status);
	}
	char* parent = "I'm parent";
	char* child = "I'm child";
	printf("%s with the PID: %d and I'm done.\n", getpid() == pid ? parent : child, getpid());
}
