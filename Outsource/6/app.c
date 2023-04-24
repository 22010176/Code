#include "../utils/hea.h"
float* matricesMultiple(float* a, float* b, int* size1, int* size2) {

}
int main() {
  int y = 3, x = 2;
  int* Arr = malloc(y * x * sizeof(int));
  for (int i = 0; i < y * x;i++) {
    Arr[i] = (i % x) * 10 + i % y;
  }
  for (int i = 0; i < y * x;i++) {
    if (i % x == 0) printf("\n");
    printf("%d ", Arr[i]);
  }
}