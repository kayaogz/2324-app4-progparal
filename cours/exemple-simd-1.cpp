#include <cstdio>
#include "immintrin.h"

int main()
{
  // Float
  float A[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  float B[8] = {2, 2, 2, 2, 2, 2, 2, 2};
//  float B[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  float C[8];

  __m256 vec1, vec2, vec3;

  vec1 = _mm256_loadu_ps(&A[0]);
  vec2 = _mm256_loadu_ps(&B[0]);
//  vec3 = _mm256_add_ps(vec1, vec2);
//  vec3 = _mm256_sub_ps(vec1, vec2);
//  vec3 = _mm256_mul_ps(vec1, vec2);
  vec3 = _mm256_div_ps(vec1, vec2);
  _mm256_storeu_ps(&C[0], vec3);

  for (int i = 0; i < 8; i++) {
    printf("%f ", C[i]);
  }
  printf("\n");

// ---------------------------
  // Int

  int Aint[8]  = {0, 1, 2, 3, 4, 5, 6, 7};
  int Bint[8]  = {2, 2, 2, 2, 2, 2, 2, 2};
  int Cint[8] ;

  __m256i vec4, vec5, vec6;
  vec4 = _mm256_loadu_si256((__m256i *)&Aint[0]);
  vec5 = _mm256_loadu_si256((__m256i *)&Bint[0]);
//  vec6 = _mm256_add_epi32(vec4, vec5);
//  vec6 = _mm256_sub_epi32(vec4, vec5);
  vec6 = _mm256_mullo_epi32(vec4, vec5);
  _mm256_storeu_si256((__m256i *)&Cint[0], vec6);

  for (int i = 0; i < 8; i++) {
    printf("%d ", Cint[i]);
  }
  printf("\n");

  return 0;
}
