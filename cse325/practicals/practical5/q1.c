#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){
	
	int n;
	
	printf("Enter Number of times you want to run the fork system call: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		if(fork()==0){
			printf("Current child process pid is %d\n", getpid());
		}
	}

	return 0;
}
