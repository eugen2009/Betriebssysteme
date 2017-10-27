#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int PID = getpid();
	printf("Hello, I'm a Parent with the PID: %d\n", getpid());
	int i;
	for (i = 0; i < 3; i++) {
		if (getpid() == PID && fork() == 0) {
				printf("Child: PID: %d; PPID: %d\n", getpid(), getppid());
		}
	}
	sleep(1);
	int status;
	if (getpid() == PID) printf("I'm the parent (with the PID: %d) and im waiting for my child(ren) to complete\n", getpid());
	wait(&status);
	if (getpid() == PID) {
		printf("I'm parent");
	} else {
		printf("I'm child");
	}
	printf(" with the PID: %d and I'm done.\n", getpid());
}
