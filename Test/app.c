#include <stdio.h>

void Max(int x) {
  int tg, i = 0, max;
  scanf("%d", &max);
  for (; i < max - 1;i++) {
    scanf("%d", &tg);
    if (tg > max) max = tg;
  }
  return max;
}
void Tong(int k) {
  int tg, tong = 0, i = 0;
  for (;i < k;i++) {
    scanf("%d", &tg);
    tong += tg;
  }
  return tong;
}
void Dem(int m) {
  int X, i = 0, c, tg;
  scanf("%d", &X);
  for (int i = 0; i < m; i++) {
    scanf("%d", &tg);
    if (tg == X) c++;
  }
  return c;
}