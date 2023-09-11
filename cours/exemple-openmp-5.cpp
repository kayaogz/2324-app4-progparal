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
//  printf("Hello\n");
  int deux, trois, quatre, cinq, neuf;

#pragma omp parallel num_threads(3) default(none) shared(deux, trois, quatre, neuf)
  {

    int thid = omp_get_thread_num();
//    printf("Je suis thread %d\n", thid);

#pragma omp single
    {
      printf("thread %d cree les taches\n", omp_get_thread_num());
#pragma omp task shared(deux)
    {
      printf("thread %d execute calcul deux\n", omp_get_thread_num());
      deux = calculDeux();
    }
#pragma omp task shared(trois)
    {
      printf("thread %d execute calcul trois\n", omp_get_thread_num());
      trois = calculTrois();
    }
#pragma omp task shared(quatre)
    {
      printf("thread %d execute calcul quatre\n", omp_get_thread_num());
      quatre= calculQuatre();
    }
    }
#pragma omp taskwait
    neuf = deux + trois + quatre;
    printf("%d %d %d\n", deux, trois, quatre);
  }

  return 0;
}
