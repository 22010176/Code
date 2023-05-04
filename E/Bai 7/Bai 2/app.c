#include <stdio.h>

int main(int argc, char* argv[]) {
  char name[50];
  float tiengui, tienlai, laixuat = 0.012;
  printf("\n================================\n");
  printf("Nhap ten cua ban: ");
  gets(name);
  fflush(stdin);
  printf("Nhap so tien ban gui:");
  scanf("%f", &tiengui);
  int tiengui1 = tiengui;
  printf("Tai khoan khach hang: %s\n", name);
  printf("Thang\tTien_dau_ky\tTien_lai\tSo_du\n");
  for (int i = 1;i <= 12;i++) {
    tienlai = tiengui * laixuat;
    printf("%d.\t%.0f\t\t%.0f\t\t%.0f\n", i, tiengui, tienlai, tiengui + tienlai);
    tiengui += tienlai;
  }
  printf("Tien lai: %.2f", tiengui - tiengui1);
}