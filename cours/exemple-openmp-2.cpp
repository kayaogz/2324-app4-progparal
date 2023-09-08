#include <iostream>
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

int main()
{
  printf("Hello\n");
  int deux, trois, quatre, cinq, neuf;

#pragma omp parallel num_threads(2) default(none) shared(deux, trois, quatre)
  {

    int thid = omp_get_thread_num();
    printf("Je suis thread %d\n", thid);

#pragma omp sections
    {
#pragma omp section
      {
        printf("section 1 par thread %d\n", thid);
        deux = calculDeux();
      }
#pragma omp section
      {
        printf("section 2 par thread %d\n", thid);
        trois = calculTrois();
      }
#pragma omp section
      {
        printf("section 3 par thread %d\n", thid);
        quatre = calculQuatre();
      }
    } // barriere implicite

  } // barriere implicite
  cinq = deux + trois;
  neuf = deux + trois + quatre;

  printf("cinq = %d\n", cinq);
  return 0;
}
