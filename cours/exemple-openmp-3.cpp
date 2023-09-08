#include <iostream>
#include <unistd.h>
#include <vector>
#include "omp.h"

int main()
{
  printf("Hello\n");

  int i;
  int N = 100000000;
  std::vector<int> A(N);

//  for (i = 0; i < A.size(); i++) {
//    A[i] = i;
//  }


//    int thid = omp_get_thread_num();
//    int numth = omp_get_num_threads();
//    printf("Je suis thread %d/%d\n", thid, numth);

#pragma omp parallel num_threads(4) default(none) shared(A, N)
  {

    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();
    printf("Je suis thread %d/%d\n", thid, numth);

#pragma omp sections
    {
#pragma omp section
      {
        printf("Section 0 thread %d\n", thid);
        int begin = 0;
        int end = N / 4;
        for (int i = begin; i < end; i++) {
          A[i] = i;
        }
      }
#pragma omp section
      {
        printf("Section 1 thread %d\n", thid);
        int begin = N / 4;
        int end = 2 * N / 4;
        for (int i = begin; i < end; i++) {
          A[i] = i;
        }
      }
#pragma omp section
      {
        printf("Section 2 thread %d\n", thid);
        int begin = 2 * N / 4;
        int end = 3 * N / 4;
        for (int i = begin; i < end; i++) {
          A[i] = i;
        }
      }
#pragma omp section
      {
        printf("Section 3 thread %d\n", thid);
        int begin = 3 * N / 4;
        int end = N;
        for (int i = begin; i < end; i++) {
          A[i] = i;
        }
      }
    } // barriere implicite
  } // barriere implicite

//  for (auto i : A)
//    printf("%d ", i);
//  printf("\n");

  return 0;
}
