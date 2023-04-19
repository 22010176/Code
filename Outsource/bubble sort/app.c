#include <stdio.h>
int main() {
  int a[9] = { 1, 54, 3, 5, 3, 5, 3, 56, 9 };
  int len = 9;
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len;j++) {
      if (a[j] > a[i]) {
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }
  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
}