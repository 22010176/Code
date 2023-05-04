#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);
  switch (a)
  {
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    printf("31 ngay");
    break;
  case 2:
    printf("28 - 29 ngay");
  default:
    if (a > 11) printf("Ko co thang");
    else printf("30 ngay");
    break;
  }
}