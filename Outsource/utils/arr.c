#include "hea.h"


void swap(float* a, float* b);
int check(float* arr, float ite, int len, int time);
float* insertSort(float* a, int len);
float* autoGenerateArr(int len);
float* CreateArr(int len);
void printArr(float* a, int len);
int findAbsMax(float* A, int size);

void swap(float* a, float* b) {
  float temp = *a;
  *a = *b; *b = temp;
}
int check(float* arr, float ite, int len, int time) {
  for (int i = 0, c = 0; i < len; i++) {
    if (arr[i] == ite) c++;
    if (c == time) return 1;
  }
  return 0;
}
static float SortingInsert(float* a, int len) {
  for (int i = len - 1;i >= 0;i--) {
    if (!(a[i] <= a[i - 1] && i - 1 >= 0)) break;
    swap(a + i, a + i - 1);
  }
}
float* insertSort(float* a, int len) {
  float* b = malloc(len * sizeof(float));
  for (int i = 0; i < len; i++) {
    b[i] = a[i];
    SortingInsert(b, i + 1);
  }
  return b;
}
float* autoGenerateArr(int len) {
  float* arr = malloc(len * sizeof(float));
  for (int i = 0; i < len; i++) arr[i] = (float)rand();
  return arr;
}
float* CreateArr(int len) { return malloc(len * sizeof(float)); }
void printArr(float* a, int len) { for (int i = 0; i < len; i++) printf("%f ", a[i]); }

int findAbsMax(float* A, int size) {
  float max = A[0]; int index;
  for (int i = 1; i < size; i++) {
    int item = A[i] > 0 ? A[i] : -A[i];
    if (item > max) { max = item; index = i; };
  }
  return index;
}