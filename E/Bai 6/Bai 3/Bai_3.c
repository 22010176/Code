#include <stdio.h>

int main() {
  float a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  float max = (a < b && a < c) ?
    a :
    (b < a && b < c ? b : c);

  printf("%lf", max);
}