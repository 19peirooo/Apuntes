#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COUNT 100


int main(int argc , char** argv){
	printf("Hello (pid: %d)\n", getpid());
	int rc = fork();
	if (rc < 0){
		fprintf(stderr, "fork failed \n");
		exit(1);
	}
	else if (rc == 0){
		printf("Hello, i am child (pid: %d)\n", getpid());
		char *myargs[3];
		myargs[0] = strdup("wc");
		myargs[1] = strdup("p3.c");
		myargs[2] = NULL;
		execvp(myargs[0], myargs);
		printf("This shouldn't print");
	}
	else{
		int rc_wait = wait(NULL);
		printf("Hello, I'm a parent of %d (rc_wait: %d) (pid: %d)\n", rc, rc_wait, getpid());
	}
}
