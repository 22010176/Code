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
char** split(char* A, int len, char B) {
  char* b = strstr(A, 32);
  printf(b);
}
void swap(char* A, char* B) {
  printf("%s\n", A);
  printf("%s\n", B);
}
int _A(char* A, char* B) { return 1; }
char** SortingString(char** A, int len, int (*compare)(char*, char*)) {
  if (compare == NULL) compare = _A;
  for (int i = 0; i < len - 1;i++) {
    // printf("%d. %s \n", i + 1, A[i]);
    swap(*(A + i), *(A + i + 1));
  }
}
int main() {
  // 1
  char** sinhVien = malloc(50 * sizeof(char*));
  for (int i = 0; i < 50; i++) {
    sinhVien[i] = calloc(30 + 1, sizeof(char));
    sinhVien[i][30] = '\0';
  }

  int i, n = 8;
  // char a[] = "ASDFASFasfd";
  strcpy(sinhVien[0], "Nguyen Thi Ngoc Anh");
  strcpy(sinhVien[1], "Dinh Thi Ngoc Anh");
  strcpy(sinhVien[2], "Nguyen Tung Lam");
  strcpy(sinhVien[3], "Nguyen Tung Lam An");
  strcpy(sinhVien[4], "Doan Vu Mai Anh");
  strcpy(sinhVien[5], "Doan Vu Mai An");
  strcpy(sinhVien[6], "Doan Vu Mai E");
  strcpy(sinhVien[7], "Doan Vu Ed Anh");
  SortingString((char**)sinhVien, n, NULL);
  // 2
  // nhapN(&n);
  // for (i = 0; i < n;i++) {
  //   printf("\nNhap ten sinh vien %d: ", i + 1);
  //   gets(sinhVien[i]);
  //   fflush(stdin);
  // }
  // 3
  // for (i = 0; i < n;i++) printf("%d. %s\n", i + 1, format(StripSpace(sinhVien[i])));
  // 4

}


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
  for (int i = 0, c = 0, j = 0; i < len;i++) {
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
  int len = strlen(A);
  char* C = malloc((len + 1) * sizeof(char));
  C[len] = '\0';
  for (int i = 0; i < len;i++) {
    C[(i + num) % len] = A[i];
  }
  return C;
}

char* StrEncode(char* A, char (*func)(int)) {
  char* C = malloc((strlen(A) + 1) * sizeof(char));
  for (int i = 0; i < strlen(A);i++) C[i] = func(A[i]);
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
  for (int i = 0; i < strlen(A);i++) {
    C[i] = (A[i] + num - 32) % 95 + 32;
  }
  C[strlen(A)] = '\0';
  return C;
}