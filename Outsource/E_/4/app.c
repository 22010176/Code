#include "../utils/hea.h"

int i, j, k, c;
int* del(int* a, int log, int len) {
  int* b = malloc(sizeof(int) * (len - 1));
  for (i = 0, c = 0; i < len; i++) {
    if (i == log) {
      c++;
      continue;
    }
    b[i - c] = a[i];
  }
  return b;
}
void main() {
  int len = 10;
  int* a = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    *(a + i) = i * 3;
  }
  a = del(a, 4, len);
  for (int i = 0; i < len - 1; i++) {
    printf("%d ", a[i]);
  }
}