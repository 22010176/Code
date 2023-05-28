#include <stdio.h>
#include <string.h>
int main() {
  char a[1000];
  gets(a);
  int i, c = 1;
  for (i = 2; i < strlen(a); i++) if (a[i - 1] == ' ') c++;
  printf("%d", c);
}