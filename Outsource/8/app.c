#include <stdio.h>
#include <stdlib.h>

int swap(int* a, int* b) {
  int temp = *a; *a = *b, * b = temp;
}
void printArr(int* a, int len) {
  for (int i = 0; i < len; i++) printf("%d ", a[i]);
}
void inputArr(int* a, int len) {
  for (int i = 0; i < len; i++) scanf("%d", a + i);
}
int SortingInsert(int* a, int len) {
  for (int i = len - 1;i >= 0;i--) {
    if (!(a[i] <= a[i - 1] && i - 1 >= 0))break;
    swap(&a[i], &a[i - 1]);
  }
}
int* insertSort(int* a, int len) {
  int* b = (int*)malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    b[i] = a[i];
    SortingInsert(b, i + 1);
  }
  return b;
}

int main() {
  int* a = malloc(50 * sizeof(int)), n = 50;
  do {
    scanf("%d", &n);
  } while (2 > n || n > 50);
  inputArr(a, n);
  printArr(insertSort(a, n), n);
}