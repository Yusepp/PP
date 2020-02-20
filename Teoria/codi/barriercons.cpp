#include <iostream>
#include <omp.h>

using namespace std;

int main(void)
{
  int tid;

  #pragma omp parallel private(tid)
  {
    tid = omp_get_thread_num();
    cout << "Hola, soc " << tid << endl;

    #pragma omp barrier // Barrera explicita

    cout << "Adeu, soc " << tid << endl;
  } // Barrera implicita
}
