#include<stdio.h>
#include<pthread.h>

int arr[10] = {99, 22, 00, 88, 11, 100, 33, 66, 44, 55};

int arr_first_half[5], arr_second_half[5], final_arr[10];

void *individual_sort(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			if(arr_first_half[i] < arr_first_half[j]){
				int temp = arr_first_half[i];
				arr_first_half[i] = arr_first_half[j];
				arr_first_half[j] = temp;
			}
			if(arr_second_half[i] < arr_second_half[j]){
				int temp = arr_second_half[i];
				arr_second_half[i] = arr_second_half[j];
				arr_second_half[j] = temp;
			}
		}
	}

	pthread_exit(NULL);
}


void *final_merge_sort(){
	for(int i=0; i<5; i++){
		final_arr[i] = arr_first_half[i];
		final_arr[i+5] = arr_second_half[i];
	}

	printf("Merged array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", final_arr[i]);
	}
	printf("\n");

	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(final_arr[i] < final_arr[j]){
				int temp = final_arr[i];
				final_arr[i] = final_arr[j];
				final_arr[j] = temp;
			}
		}
	}

	printf("Final Merged & Sorted array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", final_arr[i]);
	}
	printf("\n");
	printf("\n");

	pthread_exit(NULL);
}


int main()
{
	printf("\nInitial array is: ");
	for(int i=0; i<10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	for(int i=0; i<5; i++){
		arr_first_half[i] = arr[i];
		arr_second_half[i] = arr[i+5];
	}

	pthread_t parent_thread;
	pthread_create(&parent_thread, NULL, individual_sort, NULL);
	pthread_join(parent_thread, NULL);

	printf("First half sorted array is: ");
	for(int i=0; i<5; i++){
		printf("%d ", arr_first_half[i]);
	}
	printf("\n");

	printf("Second half sorted array is: ");
	for(int i=0; i<5; i++){
		printf("%d ", arr_second_half[i]);
	}
	printf("\n");

	pthread_create(&parent_thread, NULL, final_merge_sort, NULL);
	pthread_join(parent_thread, NULL);

	return 0;
}
