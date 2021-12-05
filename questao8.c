#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {

	int n;
	printf("Qual o tamanho do vetor?\n");
	scanf("%d", &n);
	int a[n];
   long thread_count = strtol(argv[0], NULL, 10); 	
#  pragma omp parallel for num_threads(thread_count) 
   for (int i = 0; i < n; i++){
		a[i] = i*(i+1)/2;
		printf("a[%d] = %d\n", i, a[i]);
	}
	
   return 0; 
}  /* main */


