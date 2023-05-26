#include "../utils/hea.h"
float* addMatrics(float* a, float* b, int height, int width) {
  float* c = malloc(width * height * sizeof(float));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width;j++) {
      *(c + i + j) = *(a + i + j) + *(b + i + j);
    }
  }
  return c;
}
void printMaxtrics(float* a, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%.1f | ", *(a + i + j));
    }
    printf("\n");
  }
}
int main() {
  int height = 5, width = 3;
  float* a = malloc(height * width * sizeof(float));
  float* b = malloc(width * height * sizeof(float));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      *(a + i + j) = (float)pow((i + j + 1), ((i + 1) * 30 * (j + 1)) % 8);
      *(b + i + j) = (float)pow((i + j + 1), ((i + 1) * 29 * (j + 1) % 9));
    }
  }
  float* c = addMatrics(a, b, height, width);

  printMaxtrics(a, height, width);
  printf("+\n");
  printMaxtrics(b, height, width);
  printf("__________________\n");
  printMaxtrics(c, height, width);
}