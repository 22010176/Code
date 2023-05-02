#include <stdio.h>
#include <stdlib.h>
struct  testing { int x; };
struct test2 { struct testing* x; };



int main() {
  struct test2 a;
  a.x = malloc(9 * sizeof(struct test2));
  for (int i = 0; i < 9; i++) {
    a.x[i].x = i;
    printf("%d ", a.x[i].x);
  }
}