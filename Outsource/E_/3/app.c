#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int* input(int a[], int val, int len) {
  int pos;
  for (int i = 0; i < len - 1;i++) {
    if (a[i] <= val && val <= a[i + 1]) pos = i + 1;
  }
  int* arr2 = malloc((len + 1) * sizeof(int));
  for (int i = 0, c = 0; i < len + 1; i++) {
    if (i == pos) {
      arr2[i] = val;
      c++;
      continue;
    }
    // printf("%d ", a[i - c]);
    arr2[i] = a[i - c];
  }
  return arr2;
}
int main() {
  int len = 14;
  int* a = calloc(len * sizeof(int), sizeof(int));

  for (int i = 0; i < len; i++) a[i] = i * 2;
  a = input(a, 17, len);
  for (int i = 0; i < len + 1; i++) {
    printf("%d ", a[i]);
  }


}