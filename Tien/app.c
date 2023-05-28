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
void inputf(double* A, int len) {
  int i;for (i = 0; i < len;i++) scanf("%lf", A + i);
}
char* _1(char* B, char a, char b) {
  char* A = malloc((strlen(B) + 1) * sizeof(char));
  int i;
  for (i = 0; i < strlen(B);i++) {
    if (B[i] == a) A[i] = b;
    else A[i] = B[i];
  }
  A[strlen(B)] = '\0';
  return A;
}
char* _137(char* B, int a) {
  int i;
  char* A = malloc((strlen(B) + 1) * sizeof(char));
  for (i = 0; i < strlen(B);i++) A[(i + a) % strlen(B)] = B[i];
  A[strlen(B)] = '\0';
  return A;
}
char* _136(char* B, int x) {
  int i;
  char* A = malloc((strlen(B) + 1) * sizeof(char));
  for (i = 0; i < strlen(B);i++) {
    if (B[i] <= 91) A[i] = ((B[i] - 65) + x) % 26 + 65;
    else A[i] = ((B[i] - 97) + x) % 26 + 97;
  }
  A[strlen(B)] = '\0';
  return A;
}
int main() {

}

