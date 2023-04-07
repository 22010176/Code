#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[]) {
  int n;
  scanf("%d", &n);
  int h = ceil(sqrt(n));
  if (n % 2 == 0) {
    printf("Ko la so nguyen to");
    return 0;
  }
  for (int i = 3;i <= h;i += 2) {
    if (n % i == 0) {
      printf("Ko la so nguyen to");
      return 0;
    }
  }
  printf("La so nguyen to");
}