#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COUNT 100

int main(void){
	printf("Hello World (pid: %d)\n", getpid());
	int rc = fork();
	
	if (rc < 0){
		fprintf(stderr, "fork failed\n");
	}
	else if (rc == 0){
		printf("Hello, I am child (pid: %d)\n", getpid());
	}
	else{
		int rc_wait =  wait(NULL);
		printf("Hello, I am parent of %d (rc_wait: %d) (pid: %d)", rc, rc_wait, getpid());
	}
	return 0;

}
