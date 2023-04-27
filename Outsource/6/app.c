#include "../utils/hea.h"
#include "../utils/matrices.c"

int main() {

  int* size1 = malloc(2 * sizeof(int));
  int* size2 = malloc(2 * sizeof(int));

  size1[0] = 2;
  size1[1] = size2[0] = 2;
  size2[1] = 2;

  float** A = createMatrix(size1);
  float** B = createMatrix(size2);
  int* size = malloc(2 * sizeof(int));
  size[0] = size1[0];
  size[1] = size2[1];

  printMaxtrics(MatrixMultiply(A, B, size1, size2), size);
}