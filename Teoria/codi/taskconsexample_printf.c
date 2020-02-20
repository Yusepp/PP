#include <unistd.h>
#include <stdio.h>
#include <omp.h>

int main(void)
{
  int i = 0;

#pragma omp parallel private(i) num_threads(4)
  {
#pragma omp single 
    {
      for(i = 0; i < 10; i++)
      {
	printf("Fil %d a iteracio i = %d\n", omp_get_thread_num(), i);
#pragma omp task
	{
	  sleep(1);
	  printf("Fil %d a tasca i = %d\n", omp_get_thread_num(), i); 
	}
      }
    } // Barrera  implícita

   printf("Fil %d despres del single\n", omp_get_thread_num()); 
  } // Barrera implícita

  printf("Fi\n");
}
