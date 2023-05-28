#include <string.h>
#include <ctype.h>
#include <stdio.h>

int main() {
  char A[1000], B[1000];
  gets(A);
  int i, c, z;
  for (i = 0, c = 1, z = 0; i < strlen(A);i++) {
    if (c && isspace(A[i])) continue;
    if (!c && isspace(A[i])) {
      c = 1;
      continue;
    }
    if (c && z) B[z++] = ' ';
    c = 0;
    B[z++] = A[i];
  }
  B[z] = '\0';
  printf(B);
}