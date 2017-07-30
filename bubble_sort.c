#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void bubble_sort(int *arr, int length){
	int temp = 0;

	for(int i=0; i<length-1; i++){
		for(int j=0; j <length-1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}


}

void bubble_sort2(int *arr, int length){
	int flag = 0;

	for(int i=0; i<length-1; i++){
		if(flag)
			break;
		flag = 1;
		for(int j=0; j <length-(1+i); j++){
			if(arr[j] > arr[j+1]){
				arr[j] ^= arr[j+1];
				arr[j+1] ^= arr[j];
				arr[j] ^= arr[j+1];
				flag = 0;
			}
		}
	}

}


int main(int argc, char *argv[]){
	int *arr = NULL, *arr2 = NULL;
	int length = 0;

	struct timeval start_point, end_point;
	double operating_time;


	if(argc < 2){
		printf("./bubble sort num_of_integer\n");
		return -1;
	}

	length = atoi(argv[1]);

	arr = (int *)malloc(sizeof(int) * length);
	arr2 = (int *)malloc(sizeof(int) * length);

	srand(time(NULL));

	for(int i=0; i<length; i++){
		arr[i] = rand() % 1000;
		arr2[i] = arr[i];
	}

	gettimeofday(&start_point, NULL);
	bubble_sort(arr, length);

	gettimeofday(&end_point, NULL); 	

	operating_time = (double)(end_point.tv_sec)+(double)(end_point.tv_usec)/1000000.0-(double)(start_point.tv_sec)-(double)(start_point.tv_usec)/1000000.0;

	printf("bubble_sort1 : %f\n",operating_time);


	gettimeofday(&start_point, NULL);
	bubble_sort2(arr2, length);
	gettimeofday(&end_point, NULL); 	

	operating_time = (double)(end_point.tv_sec)+(double)(end_point.tv_usec)/1000000.0-(double)(start_point.tv_sec)-(double)(start_point.tv_usec)/1000000.0;

	printf("bubble_sort2 : %f\n",operating_time);

	return 0;
}