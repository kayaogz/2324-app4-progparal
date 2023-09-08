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

#pragma omp parallel num_threads(3) default(none) shared(deux, trois, quatre)
  {
    int thid = omp_get_thread_num();
    printf("Je suis thread %d\n", thid);
    if (thid == 0) {
      deux = calculDeux();
    } else if (thid == 1) {
      trois = calculTrois();
    } else if (thid == 2) {
      quatre = calculQuatre();
    }
  } // barriere implicite
  cinq = deux + trois;
  neuf = deux + trois + quatre;

  printf("cinq = %d\n", cinq);
  return 0;
}
