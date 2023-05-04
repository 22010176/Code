#include <stdio.h>
int Songuyento(int x) {
  int i;
  int dem = 0;
  if (x < 2) {
    printf("\n%d la: -1", x);
  }
  else {
    for (i = 1;i <= x;i++) {
      if (x % i == 0) {
        dem += 1;
      }
    }
    if (dem == 2) {
      printf("\n%d la: 1", x);
    }
    else {
      printf("\n%d la: -1", x);
    }

  }
}
int main() {
  int Dayso[50];
  int j, n;
  printf("Nhap so phan tu cho n:");
  scanf("%d", &n);
  for (j = 0;j <= n;j++) {
    printf("\nDay so[%d] la :", j);
    scanf("%d", &Dayso[j]);
  }
  for (j = 0;j <= n;j++) {
    Songuyento(Dayso[j]);
  }

}