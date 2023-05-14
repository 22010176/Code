#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 10000

char* inputChar(int len) {
  char* ten = malloc(sizeof(char) * len);
  gets(ten);
  return ten;
}
char* reverse(char* A) {
  int len = strlen(A);
  char* B = malloc((len + 1) * sizeof(char));
  for (int i = len - 1, j = 0; i >= 0;i--, j++) B[j] = A[i];
  B[len] = '\0';
  return B;
}
char* GetName(char* A) {
  int len = strlen(A), index, nameLen = 0;
  char* B = malloc((len + 1) * sizeof(char));
  for (int i = len - 1, j = 0, c = 0;i >= 0;i--) {
    if (isspace(A[i]) && c == 1) break;
    if (isspace(A[i])) continue;
    B[j++] = A[i];
    nameLen++;
    c = 1;
  }
  B[nameLen] = '\0';
  strcpy(B, reverse(B));
  printf("%s\n", B);
}
char* StripSpace(char* A) {
  int len = strlen(A), lenC = 0;;
  char* B = malloc((len + 1) * sizeof(char));
  strcpy(B, A);
  for (int i = len - 1;i >= 0;i--) if (!isspace(B[i - 1])) {
    B[i] = '\0';
    break;
  }
  char* C = malloc((strlen(B) + 1) * sizeof(char));
  for (int i = 0, j = 0; i < strlen(B);i++) {
    if (isspace(B[i]) && j == 0) continue;
    C[j++] = B[i];
    lenC = j;
  }
  C[lenC] = '\0';
  return C;
}
char* format(char* A) {
  int len = strlen(A);
  int lenC = len;
  char* C = malloc((len + 1) * sizeof(char));
  for (int i = 0, j = 0; i < len;i++) {
    if (isspace(A[i]) && j == 1) {
      printf("3.%c %d %d\n", A[i], i, isspace(A[i]));
      continue;
    }
    if (isspace(A[i]) && j == 0) {
      j = 1;
      printf("%d %d ", i, isspace(A[i]));
    }
  }
  C[lenC] = '\0';
  // printf(C);
}
int main() {
  // 1
  // char* ten = inputChar(LEN);
  char* ten = "     Do     Duc     Minh         ";
  // 3
  // printf("%s\n", ten);
  // 4
  char upper[LEN];
  strcpy(upper, ten);
  printf("%s\n", strupr(upper));
  // 5
  GetName(ten);
  // 6
  char* A = StripSpace(ten);
  printf("%s\n", A);
  format(A);
}