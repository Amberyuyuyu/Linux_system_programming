#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

void isFile(char*);
void read_dir(char* dir, void (*func)(char*)){
	DIR* dp;
	struct dirent* sdp;
	char path[256];
	dp = opendir(dir);
	if(dp == NULL){
		perror("opendir error");
		return;
	}
	while((sdp = readdir(dp)) != NULL){
		if(strcmp(sdp->d_name,".")==0 || strcmp(sdp->d_name,"..")==0){
			continue;
		}
		sprintf(path,"%s/%s",dir,sdp->d_name);
		(*func)(path);
	}
	closedir(dp);

}
void isFile(char* name){
	int ret = 0;
	struct stat sb;
	ret = stat(name, &sb);
	if(ret == -1){
		perror("stat error");
		exit(1);
	}
	if(S_ISDIR(sb.st_mode)){
		read_dir(name,isFile);
	}
	printf("%10s\t\t%ld\n",name,sb.st_size);
}
int main(int argc, char* argv[]){
	if(argc == 1){
		isFile(".");
	}else{
		while(--argc){
			isFile(*++argv);
		}
	}
	return 0;
}
