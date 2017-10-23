#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int a = 0;

	if(fork()==0){
		a++;
		printf( "Hello, I'm a child and  my PID is %d!My parent is %d! a is %d!\n", getpid(), getppid(),a );
	}else {
		a = a + 3;
		printf("Hello, I'm a parent and my PID is %d! a is %d!\n", getpid(), a );
	}
}
