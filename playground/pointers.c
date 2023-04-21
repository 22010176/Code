#include <stdio.h>
#include <stdlib.h>

int main() {
  int len = 10000;
  int* a = (int*)malloc(len * sizeof(int));
  for (int i = 0;i < len;i++) {
    printf("%p = ", (a + i));
    // *(a + i) = 0;
    printf("%d\n", *(a + i));
  }
}