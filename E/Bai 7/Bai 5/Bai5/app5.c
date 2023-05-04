#include <stdio.h>
int main(int argc) {
  int n;
  scanf("%d", &n);
  float res = 0;
  for (int i = 1; i <= n; i++) {
    res += (1. / i);
  }
  printf("%f", res);
}