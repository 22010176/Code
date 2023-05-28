#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Average(double* A, int len) {
  double sum = 0; int i;
  for (i = 0; i < len;i++) sum += A[i];
  return sum / len;
}
double FindDistance(double x, double y) { return fabs(x - y); }
double* _125(double* A, int len) {
  double ave = Average(A, len), min = FindDistance(ave, A[0]), dis;
  double* p = A; int i;
  for (i = 1;i < len;i++) {
    dis = FindDistance(A[i], ave);
    if (dis < min) {
      min = dis;
      p = A + i;
    }
  }
  return p;
}
void inputf(double* A, int len) {
  int i;for (i = 0; i < len;i++) scanf("%lf", A + i);
}
void _12_5() {
  int n, i; scanf("%d", &n);
  double A[n]; inputf(A, n);
  printf("%.1lf", *_125(A, n));
}
int main() {
  _12_5();
}
