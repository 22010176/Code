#include <stdio.h>

int main() {
  char name[1000], birth[1000], mssv[1000], major[1000];

  gets(name);
  // fflush(stdin);
  gets(birth);
  // fflush(stdin);
  gets(mssv);
  // fflush(stdin);
  gets(major);
  // fflush(stdin);
  printf("Ho Ten: %s\nNgay sinh: %s\nMSSV: %s\nLop: %s", name, birth, mssv, major);
}