/*-----------------------------------------------------------------------------------

Programa que mostra, de maneira simples, como a diretiva for paralela pode ser usada

//Gildson Bezerra dos Santos
Criado em 03/12/21

------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>   

void Hello(void);  /* Thread function */

/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   int thread_count = strtol(argv[1], NULL, 10); 
	
	//diretiva paralela for
#  pragma omp parallel for num_threads(thread_count) 
   for(int i = 0; i < 4; i++){
   	int my_rank = omp_get_thread_num();
   	
   	printf("Thread %d: Iterations %d\n", my_rank, i);
   }

   return 0; 
}  /* main */

