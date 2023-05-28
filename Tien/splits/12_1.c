#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int _121(int* A, int len) {
  int x = 0;
  int i;
  for (i = 0; i < len;i++) if (A[i] % 2 == 0) x++;
  return x;
}

void inputf(int* A, int len) {
  int i;for (i = 0; i < len;i++) scanf("%d", A + i);
}
void _12_5() {
  int n, i; scanf("%d", &n);
  int A[n];
  inputf(A, n);
  printf("%d", _121(A, n));
}
int main() {
  _12_5();
}