#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
float add(float a, float b) {
  return a + b;
}
float b(int* a, float (*A)(float, float)) {
  float c = A(a[0], a[1]);
  printf("%f", c);
  return 0;
}
// float (*A)(float, float);
int main() {
  // A = add;
  int* __a = malloc(2 * sizeof(int));
  __a[0] = 9; __a[1] = 4;
  b(__a, add);
}