#include <stdio.h>

int main() {
  for (int i = 10;i > 0;i--) {
    for (int k = 0;k < i;k++) {
      printf("*");
    }
    printf("\n");
  }
  int height;
  printf("Nhap vao chieu cao tam giac: ");
  scanf("%d", &height);

  for (int i = 0;i < height;i++) {
    int gap = height - i;
    for (int j = 0;j < gap;j++) {
      printf(" ");
    }
    for (int k = 0;k < i;k++) {
      printf("* ");
    }
    printf("\n");
  }
}