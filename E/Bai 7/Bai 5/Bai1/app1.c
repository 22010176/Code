#include <stdio.h>

int main(int argc, char* argv[]) {
  for (int i = 65;i <= 90;i++) {
    printf("%d %c\n", i % 65 + 1, i);
  }
}