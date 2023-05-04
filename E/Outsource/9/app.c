#include "../utils/hea.h"
#include "../utils/matrix.c"

float fill(int i, int j) { return rand() % 1000; }
int main() {
  int* size = Vector2d(3, 3);
  float** A = FillMatrix(createMatrix(size), size, fill);
  for (int i = 0; i < 3;i++) A[i][i] = 0;
  printMaxtric(A, size);

  printMaxtric(TriangularMatrix(A, size), size);
}