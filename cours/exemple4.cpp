#include <cstdio>
#include "omp.h"

void f()
{
  printf("Hello\n");
}

void g()
{
  printf("World\n");
}

int fib(int n)
{
  if (n <= 2) return 1;
  int x, y;
#pragma omp task shared(x)
  x = fib(n - 1);
#pragma omp task shared(y)
  y = fib(n - 2);
#pragma omp taskwait
  return x + y;
}

int main()
{
#pragma omp parallel num_threads(3)
  {
//#pragma omp single
//    {
//#pragma omp task
//      {
//        f();
//      }
//#pragma omp task
//      {
//        g();
//      }
//    }
#pragma omp single
    printf("%d\n", fib(10));
  }



  return 0;
}
