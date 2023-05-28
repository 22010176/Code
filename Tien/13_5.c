#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
char* _135(char* B, char a, char b) {
  char* A = malloc((strlen(B) + 1) * sizeof(char));
  int i;
  for (i = 0; i < strlen(B);i++) {
    if (B[i] == a) A[i] = b;
    else A[i] = B[i];
  }
  A[strlen(B)] = '\0';
  return A;
}

int main() {
  char A[1000];
  char a, b;
  gets(A);fflush(stdin);
  scanf("%c", &a);fflush(stdin);
  scanf("%c", &b);
  printf("%s", _135(A, a, b));
}