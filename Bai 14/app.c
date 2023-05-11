#include <stdio.h>
#include <stdlib.h>

int main() {
  int w = 10, h = 50;
  int A[h][w];


  int* p, * p1;
  for (int i = 0; i < h;i++)
    for (int j = 0; j < w;j++) A[i][j] = i + j;


  for (int i = 0; i < h;i++) {
    for (int j = 0; j < w;j++) printf("%*d ", 2, A[i][j]);
    printf("\n");
  }

  int i = 4, j = 2;
  A[i][j] = 98;
  p = A;
  p1 = p + i * w + j;
  printf("\n%d", *p1);
}