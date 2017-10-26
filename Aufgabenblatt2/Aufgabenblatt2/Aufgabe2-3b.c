#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int PID = getpid();
	int i;
	for (i = 0; i < 3; i++) { // 3maliges ausführen
		if (getpid() == PID) {
			if (fork() == 0) { //fork beginnt nach der "for"... ein Elternprozess mit 3 Kindern?
				printf("Kind: PID: %d; PPID: %d\n", getpid(), getppid()); //Ausgabe der Kinder
			} else {
				printf("Hello, I'm a Parent with the PID: %d", getpid());
			}
		}
	}
	sleep(1); //warten auf start von jedem prozess
	int status;
	wait(&status);
	printf("... und tschüss.\n"); //Kind verabschiedet sich
}