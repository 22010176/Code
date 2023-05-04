#include "hea.h"

#define _CorS  "\033[1;"
#define _CorE "\033[1;0m"
#define DarkScale "@MBHENR#KWXDFPQASUZbdehx*8Gm&04LOVYkpq5Tagns69owz$CIu23Jcfry%1v7l+it[]{}?j|()=~!-/<>\"^_';,:`. ";
//90 - 97, 100 - 107

#define CreateString(len) calloc(len + 1, sizeof(char));
#define GetNumLen(x) (int) log10(abs(x ? x : 1)) + 1;

char* numTostr(int x);
char* ConcatString(int  n, ...);
char* StrColor(int color, char* str);

#if __INCLUDE_LEVEL__ == 0
int main() {

}
#endif

char* ConcatString(int n, ...) {
  char* A = CreateString(0);
  va_list ptr; va_start(ptr, n);
  for (int i = 0; i < n;i++) {
    char* a = va_arg(ptr, char*);
    A = realloc(A, (strlen(A) + strlen(a)) * sizeof(char));
    strcat(A, a);
  }
  return A;
}
char* StrColor(int color, char* str) { return ConcatString(5, _CorS, numTostr(color), "m", str, _CorE); }
char* numTostr(int x) {
  int val = abs(x), len = GetNumLen(x);
  char* b = malloc((len + 1) * sizeof(char));
  b[len] = '\0';
  for (int i = 0; i < len; i++) {
    b[len - i - 1] = val % 10 + 48;
    val /= 10;
  }
  return b;
}

