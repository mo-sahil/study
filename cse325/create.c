#include <stdio.h>
#include <fcntl.h>

int main()
{
	int n;
	n = open("new1.txt",O_CREAT | O_WRONLY, 0777);
	printf("File Discriptor is %d.\n", n);
}
