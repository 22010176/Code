#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
  int n, c;
  scanf("%d", &n);
  printf("Tinh tong so le: 1\nTinh tong so chan:2\n");
  float a;
  scanf("%d", &c);
  if (c == 1) {
    a = n % 2 == 0 ? n - 1 : n;
    printf("%.0f\n", (a + 1) * ceil(a / 2) / 2);
    // int res = 0;
    // for (int i = 1;i <= n;i++) res += i % 2 == 0 ? 0 : i;
    // printf("%d", res);
  }
  else if (c == 2) {
    a = n % 2 != 0 ? n - 1 : n;
    printf("%.0f\n", (a + 2) * a / 4);
    // int res = 0;
    // for (int i = 1;i <= n;i++) res += i % 2 != 0 ? 0 : i;
    // printf("%d", res);
  }
}