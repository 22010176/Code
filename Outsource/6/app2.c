#include "../utils/hea.h"
#include "../utils/matrices.c"
int main() {

  int* size1 = malloc(2 * sizeof(int));
  int* size2 = malloc(2 * sizeof(int));

  size1[0] = 3;
  size1[1] = size2[0] = 4;
  size2[1] = 5;

  float** A = createMatrix(size1);
  float** B = createMatrix(size2);
}