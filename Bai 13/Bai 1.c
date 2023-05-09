#include <stdio.h>

void swap(int* a, int* b);
int* swap3(int* a, int len);
void printArr(int* arr, int len);

int main() {
  int i, j, len = 50;
  int* arr = malloc(len * sizeof(int));
  for (i = 0; i < len;i++) *(arr + i) = i;
  for (i = 0; i < len;i++) printArr(swap3(arr, len), len);
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