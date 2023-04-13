#include <stdio.h>

int main() {
  int a[2][2];
  a[0][0] = 1;
  a[0][1] = 2;
  int* b = *a;
  int* c = *a + 1;
  printf("%d, %d\n", *b, *(b + 1));
  printf("");

}