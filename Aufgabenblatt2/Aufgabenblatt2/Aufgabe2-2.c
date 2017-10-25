#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
        if(fork() == 0) {
                printf( "Hello, I'm a child. My PID is %d!\n", getpid() );
                printf( "I'm the child and I'm done!\n");
        }else {
		sleep(2);
                printf( "Waiting for my child to complete!\n");
                waitpid(getpid()+1, &status, 0);
                printf( "Hello, I'm a parent. My PID is %d!\n", getpid() );
                printf( "Status of my child: %d\n", WEXITSTATUS(status));
                printf( "I'm the parent and I'm done!\n");
        }
}
