#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* _122(double* A, int len) {
  double* z = A;
  int i;
  for (i = 1; i < len;i++) if (*z < A[i]) z = A + i;
  return z;
}
void inputf(double* A, int len) {
  int i;for (i = 0; i < len;i++) scanf("%lf", A + i);
}
void _12_2() {
  int n, i; scanf("%d", &n);
  double A[n];
  inputf(A, n);
  printf("%lf", *_122(A, n));
}
int main() {
  _12_2();
}