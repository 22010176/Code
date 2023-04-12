#include <stdio.h>

int main() {
  int i[10] = { 0,0,0,0,0,0,0,0 };
  for (int j = 0; j < 10;j++) {
    *(i + j) = 2 * j;
    // i[j] = 2 * j;
  }
  for (int j = 0; j < 10; j++) {
    printf("%p: %d\n", (i + j), i[j]);
  }
}