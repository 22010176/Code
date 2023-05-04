#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main() {
  int a;
  printf("CHUONG TRINH MAY TINH DIEN TU\n");
  printf("\tAn phim 1- Phep cong\n");
  printf("\tAn phim 2 - Phep tru\n");
  printf("\tAn phim 3 - Phep nhan\n");
  printf("\tAn phim 3 - Phep nhan\n");
  printf("\tAn phim 4 - Phep chia\n");
  printf("\tThoat: an phim khac\n");
  printf("Moi ban chon phep tinh: ");
  scanf("%d", &a);
  printf("Nhap 2 so a, b: ");
  float b, c;
  scanf("%f %f", &b, &c);
  float result = 0;
  switch (a)
  {
  case 1:
    result = b + c;
    break;
  case 2:
    result = b - c;
    break;
  case 3:
    result = c * b;
    break;
  case 4:
    result = b / c;
    break;
  }
  printf("%.4f", result);
}