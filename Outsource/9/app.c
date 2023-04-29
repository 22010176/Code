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

}
int main() {

  float** a = createMatrix2(2, 3);
  AutoFillMatrix(a, Vector2(2, 3));
  for (int i = 0, c = 0; i < 2;i++)
    for (int j = 0;j < 3;j++) a[i][j] = ++c;
  printf("%f\n", a[0][2]);
  TriangularMatrix(a, Vector2(2, 3));
}