#include<stdio.h>
#include<pthread.h>

int arr[10] = {99, 22, 00, 88, 11, 102, 33, 66, 44, 55};

void *sort(){
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(arr[i] < arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


void *min(){
	int min = arr[0];
	printf("Minimum element is = %d\n", min);
	pthread_exit(NULL);
}


void *max(){
	int max = arr[9];
	printf("Maximum element is = %d \n", max);
	pthread_exit(NULL);
}


void *avg(){
	int sum=0;
	for(int i=0;i<10;i++)
	{
		sum = sum + arr[i];
	}
	sum = sum/10;

	printf("The average of the elements = %d \n", sum);
	printf("\n");
	pthread_exit(NULL);
}


int main(){

	printf("\n");

	printf("Initial array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	pthread_t sort_thread, max_thread, min_thread, avg_thread;

	pthread_create(&sort_thread, NULL, sort, NULL);
	pthread_join(sort_thread, NULL);

	pthread_create(&max_thread, NULL, max, NULL);
	pthread_join(max_thread, NULL);

	pthread_create(&min_thread, NULL, min, NULL);
	pthread_join(min_thread, NULL);

	pthread_create(&avg_thread, NULL, avg, NULL);
	pthread_join(avg_thread, NULL);
	return 0;
}
