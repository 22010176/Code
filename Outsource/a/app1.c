#include <stdio.h>
#include <stdlib.h>

int* Ex(int* b, int len, int (*a)(int)) {
  int* c = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) c[i] = a(b[i]);
  return c;
}
int e(int x) { return x * x; }



int main() {
  int i, j;
  for (i = 0, j = 0;i < 100;i++) {
    if (i % 2 == 0) j++;
  }
  printf("So chan: %d", j);
}