#include "../utils/hea.h"
#include "../utils/matrix.c"


float sum(float* A, int size) {
  float s = 0;
  for (int i = 0; i < size; i++) s += A[i];
  return s;
}
int findNumDup(float* A, int len, int num) {
  int c = 0;
  for (int i = 0; i < len; i++) if (A[i] == num) c++;
  return c;
}
float** TriangularMatrix(float** A, int* size) {
  float** B = copyMatrix(A, size);
  int** C = createMatrix2(size[0], 2);
  for (int i = 0; i < size[0]; i++) {
    C[i][0] = i;
    C[i][1] = findNumDup(A[i], size[1], 0);
  }
}
int main() {
  int* size = MatrixSize(3, 4);
  float** a = createMatrix(size);
  for (int i = 0, c = 0; i < size[0];i++)
    for (int j = 0;j < size[1];j++) a[i][j] = ++c;
  TriangularMatrix(a, size);
}