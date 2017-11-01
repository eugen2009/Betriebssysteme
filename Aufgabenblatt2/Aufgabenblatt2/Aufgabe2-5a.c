#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
	int childcount = 0;
	const int* childpoint = &childcount;
	int pid = getpid();
	int pid2 = getpid();
	int i;
	int j = 4;
	for (i = 0; i < j; ) {
		if (getpid() == pid2) {
			fork();
			(*childpoint)++;
			if (getpid() == pid2) {
				i++;
			}
			else {
				pid2 = getpid();
				i = 0;
				j = j / 2;
				printf("Kind: PID: %d; PPID: %d\n", getpid(), getppid()); //Ausgabe der Kinder
			}
		}
	}
	sleep(1);
	int status;
	wait(&status);
	if (getpid() == pid) printf("My PID is %d and I'm waiting for %d of my children.\n", pid, *childpoint);
	char* parent = "I'm parent";
	char* child = "I'm child";
	printf("%s with the PID: %d and i'm done.\n", getpid() == pid ? parent : child, getpid());
	if (getpid() != pid) (*childpoint)--;
}