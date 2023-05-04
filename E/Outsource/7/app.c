#include <stdio.h>

int main() {
  int i, dem;
  int arr[200], result = 0;
  for (i = dem = 0; i < 200; i++) {
    if (i % 35 == 0) arr[dem++] = i;
  }
  for (i = 0; i < dem;i++) {
    printf("%d ", arr[i]);
    result += arr[i];
  }
  printf("\n_____________________________________\n");
  printf("%d", result);
}