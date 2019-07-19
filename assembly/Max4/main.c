#include <stdio.h>

extern int max(int,int);
extern int max4(int,int,int,int);

int main() {
	printf("%u\n",max(15,86));
	printf("%u\n",max4(15,86,18,34));
}

