#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	if(fork()==0){
		printf( "Hello, I'm a child and  my PID is %d!My parent is %d!\n", getpid(), getppid() );
	}else {
		printf("Hello, I'm a parent and my PID is %d!\n", getpid() );
	}
}
