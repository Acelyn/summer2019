#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	
	clock_t start,stop;
	start = clock();
	
	// sorting part
	int n[10000];

	for (int i = 0; i < 10000; i ++){
		n[i] =rand()%10000;
	}
	for (int i = 0; i < 9999; i ++){
		for (int j = i+1; j < 10000; j ++){
			if (n[i] > n[j]){
			 int tmp = n[i];
			 n[i] = n[j];
			 n[j] = tmp;
			}
		}
	}
	
	for (int i = 0; i < 10000; i ++){
			printf("%u\n", n[i]);
		}
	

	stop = clock();
	double cpuTime = (stop - start)/(double) CLOCKS_PER_SEC;
	printf("%ld\n", start);
	printf("%ld\n", stop);
	printf("This program takes %f seconds to execute\n", cpuTime);
	return 0;
}
