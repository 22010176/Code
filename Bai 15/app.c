#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int CountingSpace(char* A) {
  int len = strlen(A), c = 0;
  for (int i = 0; i < len;i++) {
    if (isspace(A[i])) c++;
  }
  return c;
}
int RemovingSpace(char* A) {
  int len = strlen(A);
  int len2 = len;
  char* B = malloc(sizeof(char) * (len + 1));
  B[strlen(A)] = '\0';
  for (int i = 0, c = 0, j = 0; i < len;i++) {
    if (A[i] == ' ') B[i] = A[i];
  }
  B[len2] = '\0';
  printf("%s\n", B);

}
int main() {
  char A[] = "123123123432      32423412    123    123";
  printf(strrchr(A, ' '));
}
