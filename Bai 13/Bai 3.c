#include <stdio.h>
#include <stdarg.h>

void swap(int* a, int* b);
int* swap3(int* a, int len);
void printArr(int* arr, int len);
void print(int n, ...);

int main() {
  int a[100];
  int* c = a, i = 0;
  for (i = 0; i < 100;i++) a[i] = i;
  for (i = 99; i--;) printf("%d\n", *(c + i));
}
void print(int n, ...) {
  va_list prt;
  va_start(prt, n);int i;
  for (i = 0; i < n;i++) {
    int z = va_arg(prt, int);
    printf("%d ", z);
  }
  va_end(prt);
}
void printArr(int* arr, int len) {
  int i = 0;
  for (; i < len; i++) printf("%d ", arr[i]);
  printf("\n");
}
int* swap3(int* a, int len) {
  int i;
  for (i = 0; i < len - 1;i++) swap(a + i, a + i + 1);
  return a;
}
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b; *b = temp;
}