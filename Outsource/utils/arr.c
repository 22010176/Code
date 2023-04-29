#include "hea.h"

int check(int arr[], int ite, int len);
int check2(int arr[], int ite, int len);
int swap(int* a, int* b);
int* insertSort(int* a, int len);
int* autoGenerateArr(int len);
int* CreateArr(int len);
void printArr(int* a, int len);
void printArrf(float* a, int len);
float findAbsMax(float* A, int size);
float* findUnique(float* A, int size, float(*f)());



int check(int arr[], int ite, int len) {
  for (int i = 0; i < len; i++) if (arr[i] == ite) return 1;
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
  *a = *b; *b = temp;
}
static int SortingInsert(int* a, int len) {
  for (int i = len - 1;i >= 0;i--) {
    if (!(a[i] <= a[i - 1] && i - 1 >= 0)) break;
    swap(a + i, a + i - 1);
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
int* CreateArr(int len) { return malloc(len * sizeof(int)); }
void printArr(int* a, int len) { for (int i = 0; i < len; i++) printf("%d ", a[i]); }
void printArrf(float* a, int len) { for (int i = 0; i < len; i++) printf("%lf ", a[i]); }
float findAbsMax(float* A, int size) {
  float max = A[0];
  for (int i = 1; i < size; i++) {
    float item = A[i] > 0 ? A[i] : -A[i];
    if (item > max) max = item;
  }
  return max;
}
static float e(float a) { return a; }
float* findUnique(float* A, int size, float(*f)()) {
  // if (f == NULL) f = e;
}