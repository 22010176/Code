#include <stdio.h>
int main() {
  printf("Nhap vao 1 so: ");
  double f, a = 1, b = 1;
  int count = 0;
  scanf("%d", &f);
  while (a > f) {
    a *= 1. / ++count;
    b += a;
  }
  printf("%.100g", b);
}