#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int n, m, o;
	char buff[40];

	n = open("sahil.txt", O_RDONLY);
	m = read(n, buff, 15);
	o = open("new2.txt", O_CREAT | O_WRONLY, 777);
	write(o,buff,m);

	return 0;
}
