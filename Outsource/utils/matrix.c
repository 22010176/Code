#include <stdio.h>
#include "arr.c"
void printMaxtrics(float** a, int* size) {
  float* max = malloc(size[0] * sizeof(float));
  for (int i = 1; i < size[0]; i++) max[i] = findMax(a[i], size[0]);
  int indent = (int)abs(ceil(log10f(findMax(max, size[0]) * 100 + 0.1))) + 2;
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) printf("|%*.2f", indent, a[i][j]);
    printf("\n");
  }
}
float** createMatrix(int* size) {
  float** A = malloc(size[0] * sizeof(float*));
  for (int i = 0; i < size[0]; i++)
    A[i] = malloc(size[1] * sizeof(float));
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1];j++)
      A[i][j] = (i * 10 + j);
  return A;
}
float** MatrixMultiply(float** A, float** B, int* size1, int* size2) {
  int* size = autoGenerateArr(2);
  size[0] = size1[0]; size[1] = size2[1];
  float** R = createMatrix(size);
  if (size1[1] != size2[0]) return NULL;
  for (int i = 0; i < size[0];i++)
    for (int j = 0; j < size[1];j++) {
      R[i][j] = 0;
      for (int k = 0; k < size1[1];k++) R[i][j] += A[i][k] * B[k][j];
    }
  return R;
}