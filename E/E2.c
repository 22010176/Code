#include <stdio.h>
#include <math.h>
float S2(int n) {
  int i;
  float sum = 0;
  for (i = 0;i <= n;i++) {
    sum += pow(i, 2);
  }
  return sum;
}
float S3(int m) {
  int j;
  float sum = 0;
  for (j = 1;j <= m;j++) {
    sum = sum + (1.0 / j);
  }
  return sum;
}
float S4(int x) {
  int j;
  float sum = 0;
  for (j = 1;j <= x;j++) {
    sum = sum + (1.0 / (2 * j));
  }
  return sum;
}
float S5(int y) {
  int j;
  float sum = 0;
  for (j = 0;j <= y;j++) {
    sum = sum + (1.0 / (2 * j + 1));
  }
  return sum;
}
float S6(int p) {
  int j;
  float sum = 0;
  for (j = 1;j <= p;j++) {
    sum = sum + (1.0 / (j * (j + 1)));
  }
  return sum;
}
float S7(int q) {
  int	 j;
  float sum = 0;
  for (j = 1;j <= q;j++) {
    sum = sum + (1 - (1.0 / (j + 1)));
  }
  return sum;
}
float S8(int z) {
  int j;
  float sum = 0;
  for (j = 0;j <= z;j++) {
    sum = sum + (1 - (1.0 / (2 * j + 2)));
  }
  return sum;
}
int main() {
  printf("Tong cua bai 2 la:%f", S2(3));
  printf("\nTong cua bai 3 la:%.2f", S3(3));
  printf("\nTong cua bai 4 la:%.2f", S4(3));
  printf("\nTong cua bai 5 la:%.2f", S5(3));
  printf("\nTong cua bai 6 la:%.2f", S6(3));
  printf("\nTong cua bai 7 la:%.2f", S7(3));
  printf("\nTong cua bai 8 la:%.2f", S8(3));
}