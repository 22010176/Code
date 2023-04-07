#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
int main(int argc) {
  int i;
  scanf("%d", &i);
  int result = 1;
  for (int j = 0; j < i; j++) {
    result *= i;
  }
  printf("%d", result);
}