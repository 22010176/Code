#include <stdio.h>
#include  <math.h>
int main() {
  // printf("Nhap vao 1 so: ");
  double f = 0.0000000001, a = 1, b = 0;
  int count = 0;
  // scanf("%f", &f);
  // printf("%f", f);
  while ((a > 0 ? a : -a) > f) {
    // printf("%d. %f ", count + 1, a);
    a = pow(-1., count) / (2. * count++ + 1.);
    // printf("%f \n", a);
    b += a;
    printf("%g %d\n", b * 4., count);
  }
}