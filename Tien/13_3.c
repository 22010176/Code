#include <string.h>
#include <stdio.h>

int main() {
  char A[1000];
  gets(A);
  printf(strrchr(A, ' ') + 1);
}