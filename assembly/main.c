#include <stdio.h>

extern long binary_checksum_c(long);

int main() {

   printf("%ld\n", binary_checksum_c(55));
}
