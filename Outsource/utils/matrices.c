#include <stdio.h>
#include "arr.c"
void printMaxtrics(float** a, int* size) {
  float* max = malloc(size[0] * sizeof(float));
  for (int i = 1; i < size[0]; i++) max[i] = findMax(a[i], size[0]);
  int indent = (int)abs(ceil(log10f(findMax(max, size[0]) * 100 + 0.1))) + 2;
  // printf("%d\n", indent);
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) printf("|%*.2f", indent, a[i][j]);
    printf("\n");
  }
}
float** createMatrix(int* size) {
  float** A = malloc(size[0] * sizeof(float*));
  for (int i = 0; i < size[0]; i++)
    A[i] = malloc(size[1] * sizeof(float));
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1];j++) {
      A[i][j] = (i * 10 + j) * 100 + 0.02;
    }
  }
  return A;
}