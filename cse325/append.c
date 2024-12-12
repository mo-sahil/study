#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int a, b, c;
	char buff[40];

	a = open("sahil.txt", O_WRONLY | O_APPEND, 777);
	b = read(0, buff, 12);
	c = write(a, buff, b);
}
