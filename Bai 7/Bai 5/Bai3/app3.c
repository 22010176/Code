#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
int main(int argc) {
  int n;
  printf("Nhap n: ");
  scanf("%d", &n);
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += i;
  }
  printf("%d", res);
}