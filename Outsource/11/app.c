#include "../utils/hea.h"
#include "../utils/str.c"
#include "../utils/matrix.c"

#define SIZE 40

#define REV Vector2d(5,2)
#define HEIGHT 50
#define SLOPE "\\_/|"
#define MAX(x, y) x > y ? x : y;

float** PrintfAxix(int* pos);
float dF(float(*func)(float x), float x0);
char** CreateField(int* size);
int** Process(int* size, int n, ...);
int** Render(int** n, int* size);


int main() {

}

float dF(float(*func)(float x), float x0) {
  float dx = 0.00001;
  return (func(x0 + dx) - func(x0)) / dx;
}
int** Render(int** n, int* size) {
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) {
      char a = n[i][j] ? '*' : '.';
      printf("%c", a);
    }
    printf("\n");
  }
}

int** Process(int* size, int n, ...) {
  va_list ptr; va_start(ptr, n);
  int** B = malloc(size[0] * sizeof(int*));
  for (int i = 0; i < size[0]; i++) B[i] = malloc(size[1] * sizeof(int));
  for (int i = 0; i < n; i++) {
    float** A = va_arg(ptr, float**);
    for (int j = 0; j < size[0]; j++)
      for (int k = 0; k < size[1]; k++) B[j][k] = MAX(B[j][k], A[j][k]);
  }
  va_end(ptr);
  return B;
}

char** CreateField(int* size) {
  char** A = malloc(size[0] * sizeof(char*));
  for (int i = 0;i < size[0];i++) A[i] = CreateString(size[1]);
  return A;
}
float** PrintfAxix(int* pos) {
  float Ren(int i, int j) { return i == pos[0] || j == pos[1] ? '#' : '.'; }
  float** A = FillMatrix(createMatrix(REV), REV, Ren);
  return A;
}