#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int _115(char a[]) {
  int i;
  for (i = 0; i < (int)(strlen(a) / 2);i++)
    if (a[i] != a[strlen(a) - i - 1]) return 0;
  return 1;
}
void _11_5() {
  char A[1000];
  fflush(stdin);
  gets(A);
  if (_115(A)) {
    printf("Co");
    return;
  }
  printf("Khong");
}

int main() {
  _11_5();
}