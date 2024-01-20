#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>


char str1[100], str2[100], result[1000];


void *concatenatestrings(){
	strcat(result, str1);
	strcat(result, str2);
	pthread_exit(NULL);
}

int main(){
	pthread_t thread;
	printf("Enter the first string: ");
	scanf("%s", str1);
	printf("Enter the second string: ");
	scanf("%s", str2);

	pthread_create(&thread, NULL, concatenatestrings, NULL);
	pthread_join(thread, NULL);

	printf("Concatinated string is: %s \n", result);
	return 0;
}
