#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

char* StripSpace(char*);
char* format(char*);
char* StrShift(char*, int);
void nhapN(int*);
void swap(char*, char*);
char** SortingString(char**, int, int (*)(char*, char*));
int com(char*, char*);
int main() {
  int i, n;
  // 1
  char** sinhVien = malloc(50 * sizeof(char*));
  for (i = 0; i < 50; i++) {
    sinhVien[i] = calloc(30 + 1, sizeof(char));
    sinhVien[i][30] = '\0';
  }
  // 2
  nhapN(&n);
  for (i = 0; i < n;i++) {
    printf("\nNhap ten sinh vien %d: ", i + 1);
    gets(sinhVien[i]);
    fflush(stdin);
    strcpy(sinhVien[i], format(StripSpace(sinhVien[i])));
  }
  // 3
  SortingString(sinhVien, n, com);
  for (i = 0; i < n;i++) printf("%d: %s\n", i + 1, sinhVien[i]);
}
int com(char* A, char* B) {
  int lenA = 0, lenB = 0;
  char* a_ = malloc((strlen(A) + 1) * sizeof(char)), * b_ = malloc((strlen(B) + 1) * sizeof(char));
  strcpy(a_, A); strcpy(b_, B);
  while (1) {
    char* A_ = strrchr(a_, ' '), * B_ = strrchr(b_, ' ');
    A_ = A_ ? A_ : a_, B_ = B_ ? B_ : b_;
    if (!(strlen(a_) && strlen(b_))) return 0;
    if (strcmp(A_, B_)) return strcmp(A_, B_);
    a_[strlen(a_) - strlen(A_)] = b_[strlen(b_) - strlen(B_)] = '\0';
  }
}
void nhapN(int* n) {
  printf("\nNhap so Nguyen: ");
  scanf("%d", n); fflush(stdin);
}
void swap(char* A, char* B) {
  char A_[strlen(A)]; strcpy(A_, A); strcpy(A, B); strcpy(B, A_);
}
char** SortingString(char** A, int len, int (*compare)(char*, char*)) {
  int i; for (i = 0; i < len;i++) for (int j = 0; j < len - i;j++) if (compare(A[j], A[j + 1]) == 1) swap(A[j], A[j + 1]);
}

char* StripSpace(char* A) {
  int len = strlen(A), lenC = 0, i, j;
  char* B = malloc((len + 1) * sizeof(char));
  strcpy(B, A);
  if (isspace(B[len - 1])) for (i = len - 1;i >= 0;i--) if (!isspace(B[i - 1])) {
    B[i] = '\0';
    break;
  }
  char* C = malloc((strlen(B) + 1) * sizeof(char));
  for (i = 0, j = 0; i < strlen(B);i++) {
    if (isspace(B[i]) && j == 0) continue;
    C[j++] = B[i]; lenC = j;
  }
  C[lenC] = '\0';
  return C;
}
char* format(char* A) {
  int len = strlen(A), lenC = len, i, c, j;
  char* C = malloc((len + 1) * sizeof(char));
  for (i = 0, c = 0, j = 0; i < len;i++) {
    if (isspace(A[i])) {
      if (c == 1) {
        lenC--;
        continue;
      }
      c = 1;
      C[j++] = ' ';
      continue;
    }
    C[j++] = isspace(C[j - 1]) || j == 0 ? toupper(A[i]) : A[i];
    c = 0;
  }
  C[lenC] = '\0';
  return C;
}