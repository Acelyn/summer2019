#include <stdio.h>

extern long int fastpow(long int,long int);

int main(void){
	int n;
	printf("Enter a number:");
	scanf("%ld", &n);
	int m;
	printf("Enter a exponent:");
	scanf("%ld", &m);
	printf("%ld to the power of %ld is %ld\n",n,m,fastpow(n,m));
} 
