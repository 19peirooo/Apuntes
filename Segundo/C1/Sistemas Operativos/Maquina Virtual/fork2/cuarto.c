#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int i = 0;
	while (i < 3){
		fork();
		i++;
		printf("%d ",i);
	}
	printf("\n");
	sleep(60);
	return 0;
}
