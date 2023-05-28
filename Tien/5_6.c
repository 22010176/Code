#include <math.h>
#include <stdio.h>
float Solve(float a, float b, float c) {
  float delta = sqrt(b * b - 4 * a * c);
  printf("%.2f\n", (-b - delta) / (2 * a));
  printf("%.2f\n", (-b + delta) / (2 * a));
}
int main() {
  float a, b, c;
  scanf("%f%f%f", &a, &b, &c);
  Solve(a, b, c);
}