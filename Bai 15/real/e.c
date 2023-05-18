#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

char* ShiftChar(char* A, int num);
char* StrEncode(char* A, char (*func)(int));
char* inputChar(int len);
char* reverse(char* A);
char* GetName(char* A);
char* StripSpace(char* A);
char* format(char* A);
char* StrShift(char* A, int num);
void nhapN(int* n) {
  printf("\nNhap so Nguyen: ");
  scanf("%d", n);
  fflush(stdin);
}
void swap(char* A, char* B) {
  char A_[strlen(A)];
  strcpy(A_, A);  strcpy(A, B);  strcpy(B, A_);
}
int _A(char* A, char* B) { return 1; }
char** SortingString(char** A, int len, int (*compare)(char*, char*)) {
  if (compare == NULL) compare = _A;
  int i, j;
  for (i = 0; i < len;i++)
    for (j = 0; j < len - i;j++) if (compare(A[j], A[j + 1]) == 1) swap(A[j], A[j + 1]);
}

int com(char* A, char* B) {
  int lenA = 0, lenB = 0;
  char* a_ = malloc((strlen(A) + 1) * sizeof(char)), * b_ = malloc((strlen(B) + 1) * sizeof(char));
  strcpy(a_, A); strcpy(b_, B);
  do {
    char* A_ = strrchr(a_, ' ');
    char* B_ = strrchr(b_, ' ');
    A_ = A_ ? A_ : a_;
    B_ = B_ ? B_ : b_;
    if (!(strlen(a_) && strlen(b_))) return 0;
    if (strcmp(A_, B_)) return strcmp(A_, B_);
    a_[strlen(a_) - strlen(A_)] = '\0';
    b_[strlen(b_) - strlen(B_)] = '\0';
  } while (1);
}
int main() {
  // 1
  int i;
  char** sinhVien = malloc(50 * sizeof(char*));
  for (i = 0; i < 50; i++) {
    sinhVien[i] = calloc(30 + 1, sizeof(char));
    sinhVien[i][30] = '\0';
  }

  int  n = 8;
  // char a[] = "ASDFASFasfd";
  strcpy(sinhVien[0], "Do Duc Nam");
  strcpy(sinhVien[1], "Do Duc Nam");
  strcpy(sinhVien[6], "Do Duc Nam");
  strcpy(sinhVien[2], "Dinh Thi Ngoc Anh");
  strcpy(sinhVien[3], "Do Duc Minh");
  strcpy(sinhVien[4], "Do Duc Anh");
  strcpy(sinhVien[7], "Do Duc A");
  strcpy(sinhVien[5], "Do Duc Minh");
  // 2
  // nhapN(&n);
  // for (i = 0; i < n;i++) {
  //   printf("\nNhap ten sinh vien %d: ", i + 1);
  //   gets(sinhVien[i]);
  //   fflush(stdin);
  // }
  // 3
  SortingString(sinhVien, n, com);
  for (i = 0; i < n;i++) {
    strcpy(sinhVien[i], format(StripSpace(sinhVien[i])));
    printf("%d: %s\n", i + 1, sinhVien[i]);
  }
  // 4

}


char* inputChar(int len) {
  char* ten = malloc(sizeof(char) * len);
  gets(ten);
  return ten;
}
char* reverse(char* A) {
  int len = strlen(A), i, j;
  char* B = malloc((len + 1) * sizeof(char));
  for (i = len - 1, j = 0; i >= 0;i--, j++) B[j] = A[i];
  B[len] = '\0';
  return B;
}
char* GetName(char* A) {
  int len = strlen(A), index, nameLen = 0, i, j, c;
  char* B = malloc((len + 1) * sizeof(char));
  for (i = len - 1, j = 0, c = 0;i >= 0;i--) {
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
    C[j++] = B[i];
    lenC = j;
  }
  C[lenC] = '\0';
  return C;
}
char* format(char* A) {
  int len = strlen(A);
  int lenC = len, i, c, j;
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
char* StrShift(char* A, int num) {
  int len = strlen(A), i;
  char* C = malloc((len + 1) * sizeof(char));
  C[len] = '\0';
  for (i = 0; i < len;i++) {
    C[(i + num) % len] = A[i];
  }
  return C;
}

char* StrEncode(char* A, char (*func)(int)) {
  int i;
  char* C = malloc((strlen(A) + 1) * sizeof(char));
  for (i = 0; i < strlen(A);i++) C[i] = func(A[i]);
  C[strlen(A)] = '\0';
  return C;
}
char Test(int a) {
  switch (a) {
  case ' ': return 'B';
  default: return a;
  }
}
char* ShiftChar(char* A, int num) {
  char* C = malloc((strlen(A) + 1) * sizeof(char));
  int i;
  for (i = 0; i < strlen(A);i++) {
    C[i] = (A[i] + num - 32) % 95 + 32;
  }
  C[strlen(A)] = '\0';
  return C;
}