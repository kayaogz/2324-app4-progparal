#include <cstdio>
#include <unistd.h>
#include "omp.h"

int calculDeux()
{
  sleep(2);
  return 2;
}

int calculTrois()
{
  sleep(3);
  return 3;
}

int calculQuatre()
{
  sleep(4);
  return 4;
}

int main(int argc, char **argv)
{
  int deux, trois, quatre, cinq, neuf;
  printf("avant parallel\n");
#pragma omp parallel num_threads(10)
  {
    int thid = omp_get_thread_num();
    int nthreads = omp_get_num_threads();
    printf("hello from %d/%d\n", thid, nthreads);
#pragma omp sections
    {
#pragma omp section
      {
        quatre = calculQuatre();
      }
#pragma omp section
      {
        deux = calculDeux();
      }
#pragma omp section
      {
        trois = calculTrois();
      }
    }
  }
  cinq = deux + trois;
  neuf = deux + trois + quatre;
  printf("cinq = %d\n", cinq);
  printf("neuf = %d\n", neuf);
  return 0;
}
