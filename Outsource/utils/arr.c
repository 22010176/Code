#include <stdio.h>
int check(int arr[], int ite, int len) {
  for (int i = 0; i < len; i++)
    if (arr[i] == ite) return 1;
  return 0;
}
int check2(int arr[], int ite, int len) {
  for (int i = 0, c = 0; i < len; i++) {
    if (arr[i] == ite) c++;
    if (c == 2) return 1;
  }
  return 0;
}
int swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
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
int* autoGenerateArr(int len) {
  int* arr = malloc(len * sizeof(int));
  for (int i = 0; i < len; i++) {
    int ran = rand();
    arr[i] = ran;
  }
  return arr;
}
void printArr(int* a, int len) {
  for (int i = 0; i < len; i++) printf("%d ", a[i]);
}