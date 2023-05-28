#include <string.h>
#include <stdio.h>
#include <conio.h>

int main() {
  char A[100];
  gets(A);
  int i, z = 0;
  for (i = 0; i < strlen(A);i++) z += A[i] == ' ';
  printf("%d", z);
}