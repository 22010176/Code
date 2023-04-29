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

  int* sizeI = Vector2(size[0], size[0]);
  for (int i = 1; i < size[0];i++) {
    float** I = I3(size[0], -B[i][0] / B[0][0], Vector2(i, 0));
    ReplaceMatrix(B, MatrixMultiply(I, B, sizeI, size), size);
  }
  // printMaxtrics2(B, size[0] - 1, size[1] - 1);
  float** C = CutMatrix(B, size, Vector2(0, 0));
  if (size[0] - 1 > 1 && size[1] - 1 > 1) TriangularMatrix(C, Vector2(size[0] - 1, size[1] - 1));
  printMaxtrics(C, Vector2(size[0] - 1, size[1] - 1));
}

int main() {
  int* size = Vector2(5, 5);
  float** a = createMatrix(size);
  // AutoFillMatrix(a, size);
  for (int i = 0, c = 0; i < size[0];i++)
    for (int j = 0;j < size[1];j++) a[i][j] = ++c;
  printMaxtrics(a, size);
  // TriangularMatrix(a, size);
}