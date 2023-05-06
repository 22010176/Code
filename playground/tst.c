#include <stdio.h>
#include <math.h>

int main() {
  float A[100];
  for (int i = 0; i < 100;i++) {
    *(A + i) = i; // A[i] = i
  }
  for (int i = 0; i < 100;i++) {
    printf("%*.2f %s", 5, *(A + i), (i + 1) % 20 == 0 ? "\n" : "");
  }
}


