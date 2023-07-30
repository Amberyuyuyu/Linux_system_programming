#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]){
	pid_t pid;
	int i = 0;
	for(i=0; i<5; i++){
		if((pid=fork()) == 0){
			break;
		}
	}
	if(5 == i){
		sleep(5);
		printf("I'm parent,pid = %d\n",getpid());
	}else{
		sleep(i);
		printf("I'm the %dth child, pid = %d\n",i+1,getpid());
	}
	return 0;
}
