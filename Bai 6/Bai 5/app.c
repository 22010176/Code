#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f %.2f
int main() {
  float a, b, c;
  float x1, x2;
  scanf("%f %f %f", &a, &b, &c);
  float Delta = (b * b - 4 * a * c);
  if (a == 0) {
    if (c != 0) printf("%.2f", -b / c);
    else printf("Vo ngiem");
  }
  else if (Delta < 0) printf("Vo ngiem");
  else {
    Delta = sqrt(Delta);
    x1 = (-b + Delta) / (2 * a);
    x2 = (-b - Delta) / (2 * a);
    if (Delta == 0) printf("x = %.2f", x1);
    else printf("x1=%.2f x2=%.2f", x1, x2);
  }


}