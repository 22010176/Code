#include <stdio.h>

int main() {
  int a, loaiVe, ngayXem; char tenPhim[100];
  printf("Nhap ten Phim: ");
  gets(tenPhim);
  printf("\nSo luong ve: ");
  scanf("%d", &a);
  printf("\nLoai ve (1 - tre em | khac - nguoi lon): ");
  scanf("%d", &loaiVe);
  printf("\nNgay xem (1 - CN | khac - ngay thuong): ");
  scanf("%d", &ngayXem);
  printf("Thong tin ve:\n-Ten phim: %s\n-Ngay xem: %s\n-So luong ve: %d\n-So tien thanh toan: %.2f", tenPhim, ngayXem == 1 ? "CN" : "Ngay thuong", a, a * (ngayXem == 1 ? 10 : 7) * (loaiVe == 1 ? .5 : 1));
}