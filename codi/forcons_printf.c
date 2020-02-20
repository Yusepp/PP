#include <stdio.h>
#include <omp.h>

int main(void)
{
  int n = 10, i;

#pragma omp parallel shared(n) private(i)
  {
#pragma omp for
    for(i = 0; i < n; i++) {
      printf("Fil %d a i = %d\n", omp_get_thread_num(), i);
    } // Fi de la construccio for
   
   printf("Fi de la tasca pel fil %d\n", omp_get_thread_num()); 

  } // Fi de la construccio paral·lela


  return 0;
}
