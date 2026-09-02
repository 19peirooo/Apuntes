#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_COUNT 10

int main(void){

        int pid,i;

        fork();
	pid = (int)getpid();
        for (i = 1; i <= MAX_COUNT; i++){
                printf("This line is from PID = %d, Value = %d\n",pid,i);
        }
        return 0;
}
