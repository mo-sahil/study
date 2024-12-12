#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	printf("P1 PID : %d \n", (int) getpid());
	
	pid_t pid = fork();
	
	if(pid == 0)
	{
		printf("P5 PID : %d Parent P1 PID : %d\n", (int) getpid(), (int) getppid());
		pid_t pid_1 = fork();
		if(pid_1 == 0)
		{
			printf("P6 PID : %d Parent P5 PID : %d \n", (int) getpid(), (int) getppid());
			
			pid_t pid_2 = fork();
			sleep(5);
			
			if(pid_2 == 0)
			{
				printf("Zombie process P7's PID: %d \n", (int) getpid());
				printf("Parent P6 PID : %d \n", (int) getppid());
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
	
	else
	{
		pid = fork();
		if(pid == 0)
		{
			printf("P2 PID : %d Parent P1 PID : %d\n", (int) getpid(), (int) getppid());
			pid_t pid_1 = fork();
			if(pid_1 == 0)
			{
				printf("P3 PID : %d Parent P2 PID : %d \n", (int) getpid(), (int) getppid());
			
				pid_t pid_2 = fork();
				if(pid_2 == 0)
				{
					sleep(3);
				}
				else
				{
					printf("Orphan child process P4's PID : %d \n", (int) pid_2);
					printf("P4's New Parent PID : %d \n", (int) getppid());
				}
			}
			else
			{
				exit(0);
			}
		}	
	}
	
	return 0;
}
