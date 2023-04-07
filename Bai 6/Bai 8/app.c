#include <stdio.h>

int main() {
  float a;
  scanf("%d", &a);
  if (0 <= a && a < 5) printf("kem");
  else if (5 <= a && a < 7) printf("tb");
  else if (7 <= a && a < 8)printf("kha");
  else if (8 <= a && a < 9) printf("gioi");
  else if (a <= 10)printf("Xuat xac");
}