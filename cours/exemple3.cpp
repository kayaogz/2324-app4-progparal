#include <cstdio>
#include <unistd.h>
#include <vector>
#include "omp.h"


int main(int argc, char **argv)
{
  std::vector<int> A(10000);
  int somme = 0;
//  for (int i = 0; i < A.size(); i++) {
//    A[i] = i;
//  }
#pragma omp parallel num_threads(2)
  {
    int thid = omp_get_thread_num();
    int nthreads = omp_get_num_threads();
//    int sommeLoc = 0;
    printf("hello from %d/%d\n", thid, nthreads);
#pragma omp for
    for (int i = 0; i < A.size(); i++) {
      A[i] = i;
    }

#pragma omp for reduction(+:somme)
    for (int i = 0; i < A.size(); i++) {
      somme = somme + A[i];
//      sommeLoc = sommeLoc + A[i];
    }
//#pragma omp atomic
//    somme = somme + sommeLoc;
  }
  printf("somme: %d\n", somme);
  for (int i = 0; i < A.size(); i++) {
    if (A[i] != i) printf("erreur\n");
  }
  return 0;
}
