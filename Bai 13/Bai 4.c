#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include <math.h>
int min(int* a, int len);
void print(float* A, int len);
void print2(int* A, int len);

int main() {
  int d, i;
  scanf("%d", &d);
  int NamLamViec[d];
  float luong[d];

  for (i = 0; i < d;i++) {
    NamLamViec[i] = i + 1997;
    luong[i] = 2893 + i;
  }
  print2(NamLamViec, d);

  print(luong, d);
  int now = 9000;
  for (i = 0; i < d;i++) {
    float current = (now - NamLamViec[i]) / 3;
    luong[i] *= pow(1.01, (int)current);
  }
  print(luong, d);
}
void print(float* A, int len) {
  int i;
  for (i = 0; i < len;i++) {
    printf("%.2f ", *(A + i));
    if ((i + 1) % 10 == 0) printf("\n");
  }
  printf("\n");
}
void print2(int* A, int len) {
  int i;
  for (i = 0; i < len;i++) {
    printf("%d ", *(A + i));
    if ((i + 1) % 10 == 0) printf("\n");
  }
  printf("\n");
}
int min(int* a, int len) {
  int min = a[0], i, c;
  for (i = 0; i < len; i++) if (min > a[i]) {
    min = a[i];
    c = i;
  }
  return c;
}