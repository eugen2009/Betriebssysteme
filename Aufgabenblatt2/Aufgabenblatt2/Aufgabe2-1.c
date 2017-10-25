#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int status = 0;
	int childid = fork(); 
	if(childid == 0) {
		sleep(2);
        	printf( "Hello, I'm a child. My PID is %d!\n", getpid() );
		printf( "I'm the child and I'm done!\n");
	}else {
		printf( "Waiting for my child to complete!\n");
		wait(&status);
		printf( "Hello, I'm a parent. My PID is %d!\n", getpid() );
		printf( "Status of my child: %d + %d \n", WEXITSTATUS(status), status);
		printf( "I'm the parent and I'm done!\n");
	}
}

