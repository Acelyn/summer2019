#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern long int array_sum(long int*, long int );

int main(void) {
	clock_t start,stop;
	start = clock();

	long int nums[] = {1,2,3,4,5,6,7,8,9,10};
	//passing the starting address of the array in memory


	printf("%ld\n" ,array_sum(nums, 10));
	stop = clock();
	double cpuTime = (stop - start)/(double) CLOCKS_PER_SEC;
	printf("%ld\n", start);
	printf("%ld\n", stop);
	printf("This program takes %f seconds to execute\n", cpuTime);
}

