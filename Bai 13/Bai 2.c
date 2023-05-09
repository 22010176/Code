#include <stdio.h>
#include <stdarg.h>

void swap(int* a, int* b);
int* swap3(int* a, int len);
void printArr(int* arr, int len);
void print(int n, ...);

int main() {
  int x, y, z;
  int* p = &x, * q = &y, * r = &z;
  x = 9, y = 10; z = 8;
  printf("%d %d %d\n%d %d %d\n%p %p %p", x, y, z, *p, *q, *r, q, p, r);
  swap(&x, &y); swap(&y, &z);
  printf("%d %d %d\n%d %d %d\n%p %p %p", x, y, z, *p, *q, *r, q, p, r);
  swap(p, q); swap(q, r);
  printf("%d %d %d\n%d %d %d\n%p %p %p", x, y, z, *p, *q, *r, q, p, r);
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