#include <stdio.h>
#include <math.h>
#include <conio.h>
int main() {
  double A[100];
  int i, n;
  double max;
  scanf("%d", &n);
  if (!n) {
    printf("(return NULL)");
    return 0;
  }
  for (i = 0; i < n;i++) scanf("%lf", A + i);
  max = A[0];
  for (i = 1; i < n;i++) if (A[i] > max) max = A[i];
  printf("%lf", max);
}