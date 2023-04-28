#include <stdio.h>
#include "arr.c"
void printMaxtrics(float** a, int* size) {
  float* max = malloc(size[0] * sizeof(float));
  for (int i = 1; i < size[0]; i++) max[i] = findMax(a[i], size[0]);
  int indent = (int)abs(ceil(log10f(findMax(max, size[0]) * 100))) + 4;

  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) printf("|%*.2lf", indent, a[i][j]);
    printf("\n");
  }
}
int* MatrixSize(int x, int y) {
  int* size = malloc(2 * sizeof(int));
  size[0] = x; size[1] = y;
  return size;
}
float** createMatrix(int* size) {
  float** A = malloc(size[0] * sizeof(float*));
  for (int i = 0; i < size[0]; i++) A[i] = malloc(size[1] * sizeof(float));
  return A;
}
float** copyMatrix(float** A, int* size) {
  float** B = createMatrix(size);
  for (int i = 0; i < size[0];i++)
    for (int j = 0; j < size[1];j++) B[i][j] = A[i][j];
  return B;
}
float** MatrixMultiply(float** A, float** B, int* size1, int* size2) {
  int* size = CreateArr(2);
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
float** DecartMatrix(int size) {
  float** I = createMatrix(MatrixSize(size, size));
  for (int i = 0; i < size;i++) for (int j = 0; j < size;j++) I[i][j] = i == j;
  return I;
}
float** MatrixAddition(float** A, float** B, int* size) {
  float** C = createMatrix(size);
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) C[i][j] = A[i][j] + B[i][j];
  return C;
}
float** I1(int size, float time, int* swap) {
  float** I = DecartMatrix(size);
  I[swap[0]][swap[0]] = 0; I[swap[1]][swap[1]] = 0;
  I[swap[0]][swap[1]] = 1; I[swap[1]][swap[0]] = 1;
  return I;
}
float** I2(int size, float time, int line) {
  float** I = DecartMatrix(size);
  I[line][line] = time;
  return I;
}
float** I3(int size, float time, int* line) {
  float** I = DecartMatrix(size);
  I[line[0]][line[1]] = time;
  return I;
}
