#include <stdio.h>
#include <math.h>
int main() {
  int a, b, i;
  scanf("%d%d", &a, &b);
  int max = a > b ? a : b, min = a < b ? a : b;

  for (i = max;1;i += max) if (i % min == 0) break;
  printf("%d", i);
}