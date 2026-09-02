#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("PID Main: %d\n",getpid()); //PID del Main

	//Creo los procesos hijo del main
	fork();
	fork();
	fork();
	
	//Imprimo cada mensaje con su PID
	printf("Hello World con PID: %d.\n",getpid());
	sleep(20);
	return 0;
}
