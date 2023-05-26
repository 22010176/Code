#include <stdio.h>

int main() {
  int i, result = 0;
  for (i = 0; i <= 200;i++) {
    if (i % 35 == 0) result += i;
  }
  printf("%d\n", result);
}