#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	char buf[1024];

	int n = 0;
	int fd1 = open(argv[1],O_RDONLY);
	int fd2 = open(argv[2], O_RDWR|O_CREAT|O_TRUNC,0644);
	while((n = read(fd1,buf,1024)) != 0){
		write(fd2,buf,n);
	}
	close(fd1);
	close(fd2);
	return 0;
}
