#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>


/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {

	int n;
   int thread_count = strtol(argv[1], NULL, 10); 

#  pragma omp parallel num_threads(thread_count) 
   printf("quantidade de números\n");
   scanf("%d", &n);
   
   int i;
   double my_sum = 0.0;
   for (i = 1; i < n; i++){
#	pragma omp atomic
		my_sum += sin(i);
	}
	
	printf("soma %lf\n", my_sum);

   return 0; 
}  /* main */


