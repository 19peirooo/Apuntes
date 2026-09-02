#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main(){
	if (fork() == 0){
		printf("Hello From Child\n");
	}
	else{
		printf("Hello From Parent\n");
	}
}
