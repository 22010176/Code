#include<stdio.h>
int main()
{
  //khai bao a, b, tg
  int a, b, tg;
  scanf("%d", &a);

  scanf("%d", &b);
  while (b != 0) {
    tg = a % b;
    a = b;
    b = tg;
  }
  //in UCLN ra man hinh
  printf("%d", a);
}