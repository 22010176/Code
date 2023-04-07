#include <stdio.h>

int main() {
  int k = 0;
  for (int i = 0; i < 1000;i++) {
    int dv = i % 10;
    int chuc = i % 100 - dv;
    int tram = i - dv - chuc;
    if (dv + tram / 100 == chuc / 10 && i % 3 == 0) {
      if (k++ % 10 == 0) printf("\n");
      printf("%d ", i);
    }
  }
}