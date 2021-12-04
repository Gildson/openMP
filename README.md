# openMP

OBS:
1. As diversas tentativas de encontrar conteúdo que ensinem programação paralela de uma maneira mais simples não foram sanadas, assim resolvi começa a escrever sobre o assunto na tentativa de ajudar as pessoas que assim como eu também tiveram essa dificuldade;

2. Vou lista aqui apenas alguns ponto da programação paralela com openMP, assim teram informações que não estaram nessa arquivo, se ficar alguma dúvida, que não conseguiu encontrar aqui, pode mandar um e-mail para gildsonbsantos@gmail.com, que tentarei te ajudar;

3. Os exemplos que encontrarão aqui são retirados do livro An Introduction to Parallel Programming de Peter Pacheco e podem ser encontrados no site http://www.cs.usfca.edu/~peter/ipp/ipp-source.tgz ;

4. suponho aqui que todos tem conhecimento além do básico em programação C e c++ e utilização do sistema Linux;

5. Suponho que seu compilador tem recursos para o openMP.


Vamos começar!
Como faço para compilar e testa um programa com openMP?
Para compilar um programa com openMP, usasse a linha de comando:

$gcc -g -Wall -fopenmp -o  omp_hello omp_hello.c

e para testa usasse a linha de comando:

./omp_hello num_threads

Esse argumento num_threads é a quantidade de threads que você quer que o compilador use.

Se queremos definir a quantidade de threads que uma parte do código vai ter, utilizamos #pragma omp parallel num_threads(thread_count) antes do código.

Para evitar que todas as threads tenha acesso a variáveis globais ao mesmo tempo, utilizaremos #pragma omp critical para definir que a parte a seguir do código terá acesso mutualmente excludente.

Para medir o tempo de um processo paralelo, o tempo medido aqui é dado em segundos

inserir duas variáveis do tipo double, uma para começar a contar o tempo e outra para terminar a contagem, ambas as variáveis receberão omp_get_wtime()

* Diretiva critical # pragma omp critical

Essa diretiva permite apenas que uma thread por vez tenho acesso a uma variável global, variáveis globais são declaradas fora dos blocos paralelos.

* Diretiva de paralela # pragma omp parallel num_threads(thread_count)

Essa diretiva limite o número de threads que devem executar a próxima linha de código.

* Diretiva de paralela for # pragma omp parallel for num_threads(thread_count)

Essa diretiva é exclusiva para o loop for, tem um exemplo dele na pasta openMP.
