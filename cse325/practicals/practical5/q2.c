#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <stdlib.h>

int main()
{
	printf("Parent PID(A) : %d \n", getpid());

	pid_t pid = fork();

	if(pid == 0)
	{
		printf("Child 1 PID(B) : %d Parent(A) PID : %d\n", getpid(), getppid());
		pid_t pid_1 = fork();
		if(pid_1 == 0)
		{
			printf("Child 2(C) PID : %d Parent(B) PID (Child 1) : %d \n", getpid(), getppid());
			exit(0);
		}
		else
		{
			exit(0);
		}
	}
	else
	{
		exit(0);
	}

	return 0;
}
