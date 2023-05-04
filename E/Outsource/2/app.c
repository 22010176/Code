#include <stdio.h>
#include "../utils/arr.c"

int unique(int arr[], int len, int arr2[]) {
  int a[len], a_len = 0;
  for (int i = 0, c = 0; i < len; i++) {
    if (!check(a, arr[i], c + 1)) {
      a[c++] = arr[i];
      a_len = c;
    }
  }
  for (int i = 0, c = 0; i < a_len;i++) if (!check2(arr, a[i], len)) arr2[c++] = a[i];

}
