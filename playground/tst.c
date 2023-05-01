#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TTT {
  int a;
  char e[100];
};

int main() {
  struct TTT a, b;
  a.a = 34;
  strcpy(a.e, "hello");
  printf("%s: %d", a.e, a.a);
}