#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	char* parent  = "I'm a parent";
	char* child = "I'm a child";
	int pid = getpid();
	int i;
	for (i = 0; i < 3; i++) {
		if (getpid() == pid && fork() == 0) {
				printf("Child: PID: %d; PPID: %d\n", getpid(), getppid());
		}
	}
	if (getpid() == pid) printf("Hello, I'm a Parent with the PID: %d\n", getpid());
	sleep(1);
	int status;
	if (getpid() == pid) printf("I'm the parent (with the PID: %d) and im waiting for one  my children to complete\n", getpid());
	wait(&status);
	//if (getpid() == pid) {
	//	printf("I'm parent");
	//} else {
	//	printf("I'm child");
	//}
	printf("%s with the PID: %d and I'm done.\n", getpid() == pid ? parent : child, getpid());
}
