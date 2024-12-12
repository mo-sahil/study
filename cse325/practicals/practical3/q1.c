#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int f1, f2, size, mid;
	char buffer[1000];
	
	f1 = open("q11.txt", O_RDONLY);
	size = lseek(f1, 0, SEEK_END);
	mid = size/2;
	
	f2 = open("q12.txt", O_CREAT | O_WRONLY, 0777);
	
	lseek(f1, mid, SEEK_SET);
	read(f1, buffer, size-mid);
	write(f2, buffer, size-mid);
	
	return 0;
}
