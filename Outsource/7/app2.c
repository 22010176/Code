#include <stdio.h>
int main() {
  int i;
  int tong = 0;
  int Dayso[200];
  for (i = 0;i < 200;i++) {
    if (i % 35 == 0)
      printf("\n%d ", i);
  }
  for (i = 0;i < 200;i++)
  {
    if (Dayso[i] % 35 == 0)
      tong = tong + Dayso[i];
  }
  printf("\nTong day so da nhap la: %d", tong);
}