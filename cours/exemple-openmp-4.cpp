#include <iostream>
#include <unistd.h>
#include <vector>
#include "omp.h"

int main()
{
  printf("Hello\n");

  int i;
  int N = 10000;
  int somme = 0;
  std::vector<int> A(N);

//  for (i = 0; i < A.size(); i++) {
//    A[i] = i;
//  }

#pragma omp parallel num_threads(4) default(none) shared(A, N, somme)
  {

    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();
//    printf("Je suis thread %d/%d\n", thid, numth);

#pragma omp for reduction(+:somme)
    for (int i = 0; i < N; i++) {
//      printf("i = %d / thid = %d\n", i, thid);
      A[i] = i;
//#pragma omp atomic
      somme = somme + A[i];
    } // barriere implicite
  } 

//  for (auto i : A)
//    printf("%d ", i);
//  printf("\n");
  printf("somme = %d\n", somme);

  return 0;
}
