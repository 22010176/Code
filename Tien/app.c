#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int _115(char a[]) {
  int i;
  for (i = 0; i < (int)(strlen(a) / 2);i++)
    if (a[i] != a[strlen(a) - i - 1]) return 0;
  return 1;
}
double* _122(double* A, int len) {
  double* z = A;
  int i;
  for (i = 1; i < len;i++) if (*z < A[i]) z = A + i;
  return z;
}
int _121(int* A, int len) {
  int x = 0;
  int i;
  for (i = 0; i < len;i++) if (A[i] % 2 == 0) x++;
  return x;
}
double Average(double* A, int len) {
  double sum = 0;
  int i;
  for (i = 0; i < len;i++) sum += A[i];
  return sum / len;
}
double FindDistance(double x, double y) { return fabs(x - y); }
double* _125(double* A, int len) {
  double ave = Average(A, len), min = FindDistance(ave, A[0]), dis;
  double* p = A;
  int i;
  for (i = 1;i < len;i++) {
    dis = FindDistance(A[i], ave);
    if (dis < min) {
      min = dis;
      p = A + i;
    }
  }
  return p;
}
int main() {
  // Bai 11.5
  printf("Bai 11.5: %d\n", _115("aD3Da"));

  // Bai 12.2
  double a[3] = { 1.3,45.34,23.4 };
  double* x = _122(a, 3);
  printf("Bai 12.2: %p %lf\n", x, *x);

  // Bai 12.1
  int A[6] = { 1,2,3,4,5,6 };
  printf("Bai 12.1: %d\n", _121(A, 6));

  // Bai 12.5
  double A_[5] = { 1.2,3.45,45.35,32.3,4.5 };
  double* a_ = _125(A_, 6);
  printf("Bai 12.5: %p %lf\n", a_, *a_);

}