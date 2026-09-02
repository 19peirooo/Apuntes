#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	if (fork() == 0){
		printf("Hello From Child\n");
	}
	else{
		wait(NULL);
		printf("Hello From Parent\n");
	}
}
