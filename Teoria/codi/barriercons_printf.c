#include <stdio.h>
#include <omp.h>

int main(void)
{
  int tid;

  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    printf("Hola, soc %d\n", tid);

    #pragma omp barrier // Barrera explicita

    printf("Adeu, soc %d\n", tid);;
  } // Barrera implicita
}
