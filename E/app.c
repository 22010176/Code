#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float Bai2(int n);
float Bai3(int n);
float Bai4(int n);
float Bai5(int n);
float Bai6(int n);
float Bai7(int n);
float Bai8(int n);

#if __INCLUDE_LEVEL__ == 0
int main() {}
#endif

float Bai2(int n) {
  float sum = 0; int i;
  for (i = 1; i <= n;i++) sum += pow(i, 2);
  return sum;
}
float Bai3(int n) {
  float sum = 0; int i;
  for (i = 1; i <= n;i++) sum += 1 / i;
  return sum;
}
float Bai4(int n) {
  float sum = 0; int i;
  for (i = 1; i <= n;i++) sum += 1 / (2 * i);
  return sum;
}
float Bai5(int n) {
  float sum = 0; int i;
  for (i = 0; i <= n;i++) sum += 1 / (2 * i + 1);
  return sum;
}
float Bai6(int n) {
  float sum = 0; int i;
  for (i = 1; i <= n;i++) sum += (i + 1) / i;
  return sum;
}
float Bai7(int n) {
  float sum = 0; int i;
  for (i = 1; i <= n;i++) sum += i / (i + 1);
  return sum;
}
float Bai8(int n) {
  float sum = 0; int i;
  for (i = 0; i <= n;i++) sum += (2 * i + 1) / (2 * i + 2);
  return sum;
}
float Bai142(float n[], int len) {
  float min = n[0];
  for (int i = 1; i < len;i++)
    if (n[i] < min) min = n[0];
  return min;
}
int Bai143(int n[], int len) {
  for (int i = 0; i < len;i++)
    if (n[i] % 2 == 0) return n[i];
  return -1;
}