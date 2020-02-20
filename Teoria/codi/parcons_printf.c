#include <stdio.h>
#include <omp.h>

int main(void)
{
   printf("Inici\n"); 

#pragma omp parallel
  {
    printf("Soc el fil numero %d\n", omp_get_thread_num()); 

    if (omp_get_thread_num() == 1) {
      printf("El fil 1 fa una cosa diferent\n");
    }

    printf("Torno a ser el fil %d\n", omp_get_thread_num()); 
  } // Fi de la regio paral·lela

  printf("Fi de la construccio\n");
  return 0;
}
