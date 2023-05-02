#include <stdio.h>

enum Op {
  ADD = '+',
  SUB = '-',
};


/* add: add a and b, return result */
int add(int a, int b) {
  return a + b;
}

/* sub: subtract b from a, return result */
int sub(int a, int b) {
  return a - b;
}

/* getmath: return the appropriate math function */
int (*getmath(enum Op op))(int, int) {
  switch (op) {
  case ADD:
    return &add;
  case SUB:
    return &sub;
  default:
    return NULL;
  }
}

int main() {
  int a, b, c;
  int (*fp)(int, int);

  fp = getmath(ADD);

  a = 1, b = 2;
  c = (*fp)(a, b);
  printf("%d + %d = %d\n", a, b, c);
  return 0;
}