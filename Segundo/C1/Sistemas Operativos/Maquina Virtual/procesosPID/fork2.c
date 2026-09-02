#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COUNT 100

void childProcess(int pid){
	int i;
	for (i = 1; i <= MAX_COUNT; i++){
		printf("This line is from child process with PID = %d, Value = %d\n", pid, i);
	}
	printf("****Child Process is done****\n");
}

void parentProcess(int pid){
	int i;
        for (i = 1; i <= MAX_COUNT; i++){
                printf("This line is from parent process with PID = %d, Value = %d\n", pid, i);
        }
        printf("****Parent Process is done****\n");
}


int main(void){

        int rc;

        rc = fork();

	if (rc == 0){
		childProcess(getpid());
	}
	else{
		parentProcess(getpid());
	}
        return 0;
}
