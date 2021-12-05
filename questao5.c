#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

float sum = 0.0;
float a[] = { 4.0, 3.0, 3.0, 1000.0};

int main(int argc, char* argv[]){
# pragma omp parallel for num_threads(2) reduction(+:sum)
	for(int i = 0; i < 4; i++){
		sum += a[i];
	}
	printf("sum = %4.1f\n", sum);
	return 0;
}
