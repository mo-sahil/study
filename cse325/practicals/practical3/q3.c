#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd = open("q3.txt", O_RDONLY);
	char ch;
	while(1){
		int byte_read = read(fd, &ch, 1);
		if (byte_read == 0){
			break;
		}
		write(1, &ch, 1);
	}
	close(fd);
	return 0;
}
