#include <stdio.h>
#include <math.h>
int main() {
  int i, j;
  for (i = 20;0 < i;i--) {
    for (j = 20;0 < j;j--) {
      printf("\n%d x %d = %d ", i, j, i * j);
    }
    printf("____________");
  }
}