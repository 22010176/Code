#include <stdio.h>

int main() {
  int a;
  scanf("%d", &a);
  int tram = a / 100;
  int chuc = (a - tram * 100) / 10;
  int dv = (a - tram * 100 - chuc * 10);
  switch (tram) {
  case 1:
    printf("mot");
    break;
  case 2:
    printf("hai");
    break;
  case 3:
    printf("ba");
    break;
  case 4:
    printf("bon");
    break;
  case 5:
    printf("nam");
    break;
  case 6:
    printf("sau");
    break;
  case 7:
    printf("bay");
    break;
  case 8:
    printf("tam");
    break;
  case 9:
    printf("chin");
    break;
  }
  printf(" tram ");
  switch (chuc) {
  case 1:
    printf("muoi ");
    break;
  case 2:
    printf("hai");
    break;
  case 3:
    printf("ba");
    break;
  case 4:
    printf("bon");
    break;
  case 5:
    printf("nam");
    break;
  case 6:
    printf("sau");
    break;
  case 7:
    printf("bay");
    break;
  case 8:
    printf("tam");
    break;
  case 9:
    printf("chin");
    break;
  }
  if (chuc != 1) printf(" muoi ");
  switch (dv) {
  case 1:
    printf("mot");
    break;
  case 2:
    printf("hai");
    break;
  case 3:
    printf("ba");
    break;
  case 4:
    printf("bon");
    break;
  case 5:
    printf("nam");
    break;
  case 6:
    printf("sau");
    break;
  case 7:
    printf("bay");
    break;
  case 8:
    printf("tam");
    break;
  case 9:
    printf("chin");
    break;
  }
}