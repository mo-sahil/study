#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int n, m;
	char buff[30];

	n = open("sahil.txt", O_RDONLY);
	printf("File Discriptor value is: %d\n", n);

	m = read(n, buff, 15);
	write(1, buff, m);

	return 0;
}
