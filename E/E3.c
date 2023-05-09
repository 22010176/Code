#include <stdio.h>


int Min(int* a, int* b) {
  int min = *a;
  if (b > a) { min = *a; }
  else { min = *b; }
}


int main() {
  int SoThuc[50];
  int n, i, j;
  printf("Nhap n= ");
  scanf("%d", &n);
  for (i = 0;i <= n;i++) {
    printf("So thuc [%d]", i);
    scanf("%d", &SoThuc[i]);
  }

  for (i = 0;i <= n - 1;i++) {
    for (j = i + 1;j <= n;j++) {
      Min(&SoThuc[i], &SoThuc[j]);
    }
  }
  printf("Gia tri nho nhat cua mang 1 chieu la %d", Min(&SoThuc[i], &SoThuc[j]));
}