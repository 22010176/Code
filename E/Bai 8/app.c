#include "stdio.h"
// Bai 1,2,3
int Higher(int a, int b) {
  return a > b;
}
int SwitchVar(int* a, int* b) {
  int temp = *a;
  *a = *b; *b = temp;
}
int MinMax(int a, int b, int c, int d, int* min, int* max) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4 - i;j++) {
      switch (j) {
      case 0:
        if (Higher(a, b)) SwitchVar(&a, &b);
        break;
      case 1:
        if (Higher(b, c)) SwitchVar(&b, &c);
        break;
      case 2:
        if (Higher(c, d)) SwitchVar(&c, &d);
        break;
      }
    }
  }
  *min = a; *max = d;
}
// Bai 4
int Sum(int a, int b) {
  int res = a;
  for (int i = a;i < b;res += ++i);
  return res;
}
// Bai 5
float Power(float x, float y) {
  while (--y > 0) x *= x;
  return x;
}
