/*-----------------------------------------------------------------------------------

Programa que mostra, de maneira simples, como a diretiva for paralela pode ser usada
e a função que mede o tempo de execução do bloco paralelo
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
	
	//inicializa a contagem do tempo
	double inicio = omp_get_wtime();
	//diretiva paralela for
#  pragma omp parallel for num_threads(thread_count) 
   for(int i = 0; i < 4; i++){
   	int my_rank = omp_get_thread_num();
   	
   	printf("Thread %d: Iterations %d\n", my_rank, i);
   }

	//Finaliza a contagem do tempo
	double final = omp_get_wtime();
	
	printf("Tempo de execução %f\n", final - inicio);
   return 0; 
}  /* main */

