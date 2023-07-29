#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <pthread.h>

int main(int argc, char* argv[]){
	DIR* dp;
	struct dirent* sdp;
	dp = opendir(argv[1]);
	if(dp == NULL){
		perror("opendir error");
		exit(1);
	}
	while((sdp = readdir(dp)) != NULL){
		printf("%s\t",sdp->d_name);
	}
	printf("\n");
	closedir(dp);
	return 0;
}
