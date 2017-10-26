#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int i;
	for (i = 0; i < 3; i++) {
		if (fork() == 0) {
			printf("Kind: PID: %d; PPID: %d\n", getpid(), getppid());
		}
	}
	sleep(1);
	int status;
	wait(&status);
	printf("... und tschüss.\n");
}