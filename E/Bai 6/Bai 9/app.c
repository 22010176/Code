#include <stdio.h>
#define namNay 2023
int main() {
  int a;
  printf("ngay nam sinh: ");
  scanf("%d", &a);
  int b = namNay - a;
  if (b < 0)printf("Nhap ko hop le");
  else if (0 <= b && b < 6) printf("tre em");
  else if (6 <= b && b < 11) printf("cap 1");
  else if (11 <= b && b < 15) printf("cap 2");
  else if (15 <= b && b < 18) printf("cap 3");
  else if (18 <= b && b < 40) printf("Thanh nien");
  else if (40 <= b && b < 60) printf("Trung nien");
  else  printf("Nguoi gia");


}