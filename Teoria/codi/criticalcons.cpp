#include <iostream>
#include <omp.h>

using namespace std;

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
       cout << "tid = " << tid << " sum = " << sum << endl;
    } // No hi ha barrera implicita
    
    cout << "El fil " << tid << " ha acabat" << endl;
  } // Barrera implicita
}


