#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd, bytes_read;
	char buffer;
	fd = open("q2.txt", O_WRONLY);
	
	printf("Enter text \n");
	
	while(1){
		bytes_read = read(0, &buffer, 1);
		if(buffer == '$') break;
		write(fd, &buffer, bytes_read);
	}
	close(fd);
	
	return 0;
}
