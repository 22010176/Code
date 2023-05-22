#include <string.h>
#include <stdio.h>

int main() {
  char a[1000];
  int res = 1;
  gets(a);
  for (int i = 0; i < (int)(strlen(a) / 2);i++) {
    if (a[i] != a[strlen(a) - i - 1]) {
      res = 0;
      break;
    }
  }
  if (res) printf("Co");
  else printf("No");
}