#include <stdio.h>
#include <math.h>


int Tong(int x, int n) {
  int tong = 0;
  for (int i = 1; i <= n;i++) tong += (int)abs(pow(x, 2 * i));
  return tong;
}

int main() {
  int A = Tong(2, 9);
  printf("Tong la: %d", A);
}


