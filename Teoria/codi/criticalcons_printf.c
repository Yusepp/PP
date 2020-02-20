#include <stdio.h>
#include <omp.h>

int main(void)
{
  int sum = 0;

#pragma omp parallel shared(sum)
  {
    int local = 10;
    int tid = omp_get_thread_num();

#pragma omp critical
    {
       sum += local;
       printf("tid = %d sum = %d\n", tid, sum);
    } // No hi ha barrera implicita
    
    printf("El fil %d ha acabat\n", tid);
  } // Barrera implicita
}


