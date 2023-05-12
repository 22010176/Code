#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <conio.h>

int main() {
  char name[30] = "asfd    afaasdf    asdfasfd";
  // scanf("%s", name);
  fflush(stdin);
  printf("%s\n", name);
  strupr(name);
  printf("%s\n", name);
  char a[30], j = 0;
  // strrchr(name, ' ');
  printf("%s", strrchr(name, ' ') + 1);
}