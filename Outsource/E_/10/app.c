#include "../utils/hea.h"
#include "../utils/matrix.c"

#define _CorS  "\033[1;"
#define _CorE "\033[1;0m"
#define DarkScale "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

int getNumLength(int x);
char* numTostr(int x);
char* CreateString(int len);
char* ConcatString(int  n, ...);
char* StrColor(int color, char* str);
//90 - 97, 100 - 107

#if __INCLUDE_LEVEL__ == 0
int main() {}
#endif

char* ConcatString(int  n, ...) {
  char* A = CreateString(0);
  va_list ptr; va_start(ptr, n);

  for (int i = 0; i < n;i++) {
    char* a = va_arg(ptr, char*);
    A = realloc(A, (strlen(A) + strlen(a)) * sizeof(char));
    strcat(A, a);
  }
  return A;
}
char* StrColor(int color, char* str) {
  return ConcatString(5, _CorS, numTostr(color), "m", str, _CorE);
}
char* CreateString(int len) { return calloc(len, sizeof(char)); }
int getNumLength(int x) { return (int)log10(abs(x ? x : 1)) + 1; }
char* numTostr(int x) {
  int val = abs(x), len = getNumLength(x);
  char* b = malloc((len + 1) * sizeof(char));
  b[len] = '\0';
  for (int i = 0; i < len; i++) {
    b[len - i - 1] = val % 10 + 48;
    val /= 10;
  }
  return b;
}

