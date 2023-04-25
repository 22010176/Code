#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
char Bin(int i) { return i ? '1' : '0'; }
char* DtoB(int a) {
  int b = a, mod, i = (int)floor((a ? log2(a) : 0) + 1), d;
  char* ch = malloc((i + 1) * sizeof(char));
  ch[i] = '\0';
  do {
    ch[--i] = Bin(b % 2);
    b /= 2;
  } while (b != 0);
  return ch;
}
char* BtoG(char in[]) {
  int len = strlen(in) + 1;
  char* res = malloc((len) * sizeof(char));
  res[len - 1] = '\0';
  res[0] = in[0];
  for (int i = 1; i < len - 1; i++) res[i] = Bin(in[i - 1] != in[i]);
  return res;
}

char* fill(int len, char buff, char in[]) {
  char* ch = malloc((len + 1) * sizeof(char));
  int ch_len = strlen(in);
  ch[len] = '\0';
  for (int i = 0, c = 0; i < len; i++) ch[i] = (len - i <= ch_len) ? in[c++] : buff;
  return ch;
}


int main() {
  int bit = 7;
  int range = (int)pow(2, bit);
  for (int i = 0; i < range; i++) {
    printf(fill(bit, '0', BtoG(DtoB(i))));
    printf("\n");
  }
}