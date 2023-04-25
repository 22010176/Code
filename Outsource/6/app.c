#include "../utils/hea.h"
float* matricesMultiple(float* a, float* b, int* size1, int* size2) {

}
int main() {
  int width = 2, height = 3;
  int** arr = malloc(height * sizeof(float*));
  for (int i = 0; i < height; i++) {
    *(arr + i) = malloc(width * sizeof(float));
  }
}