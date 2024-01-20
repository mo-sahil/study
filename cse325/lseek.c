#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int n;
	char buff[40];
	n = open ("test.txt", O_RDONLY);

	read(n, buff, 10);
	write(1, buff, 10);

	lseek(n, 5, SEEK_CUR);
	read(n, buff, 10);
	write(1, buff, 10);

	return 0;
}
