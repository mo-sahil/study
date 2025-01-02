#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	printf("root process P1's PID : %d \n", (int) getpid());
	pid_t pid = fork();

	if(pid == 0)
	{
		printf("child process P4's PID : %d and parent proess P1's PID : %d\n", (int) getpid(), (int) getppid());
		printf("Child process P4 is sleeping \n");
		pid_t pid_1 = fork();
		sleep(2);
		if(pid_1 == 0)
		{
			printf("child process P5's PID : %d and parent process P4's PID : %d \n", (int) getpid(), (int) getppid());
			printf("Zombie process P5's PID : %d \n", (int) getpid());
		}
		else{
			printf("Orphan child process P4's PID : %d \n", (int) getpid());
			printf("P4's New Parent PID : %d \n", (int) getppid());
		}
	}
	else
	{
		pid = fork();
		if(pid == 0)
		{
			printf("child process P2's PID : %d and parent process P1's PID : %d \n", (int) getpid(), (int) getppid());
			pid_t pid_1 = fork();
			if(pid_1 == 0)
			{
				printf("child process P3's PID : %d and parent process P2's PID : %d \n", (int) getpid(), (int) getppid());
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
	}

	return 0;
}
