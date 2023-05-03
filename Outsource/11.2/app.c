#include "../utils/hea.h"
#include "../utils/matrix.c" 
#include "../utils/str.c"

#define SIZE 40
#define PixRat 2
#define Pos 10
int* ref;
void Render(int** Final, int* size);
int** PreProcess(int* size, int n, ...);
int getDepth(float*** Scenes, int* size, int i, int j);

float Test(int i);
float Test2(int i);
float Test3(int i);
float Test4(int i);
float Ox(int i, int j);
float Oy(int i, int j);
float e(int i) {
  float z = 0.1 * (i - 2) + 2;
  return z * z;
}
int main() {
  ref = Vector2d(100, 100);

  float** scene1 = FillMatrixFunc1(createMatrix(ref), ref, e);
  float** Ox_ = FillMatrix(createMatrix(ref), ref, Ox);
  float** Oy_ = FillMatrix(createMatrix(ref), ref, Oy);
  // float** scene2 = FillMatrixFunc1(createMatrix(ref), ref, Test3);
  // float** scene4 = FillMatrixFunc2(createMatrix(ref), ref, Test4);

  Render(PreProcess(ref, 3, Ox_, Oy_, scene1), ref);
}
float Ox(int i, int j) {
  return i == ref[0] - 2;
}
float Oy(int i, int j) {
  return j == 2;
}
float Test(int i) {
  float rat = 0.115;
  float r = 3.5;
  float x = ((float)i * rat) - Pos;
  return sqrt(r * r - x * x) / rat + Pos;
}
float Test4(int i) {
  int A = 9;
  return sin(i * .5) * A + A + 5;
}
float Test3(int i) {
  float rat = 0.115;
  float r = 3;
  float x = ((float)i * rat) - Pos;
  return -sqrt(r * r - x * x) / rat + Pos;
}
float Test2(int i) {
  return i * 2;
}

void Render(int** Final, int* size) {
  for (int i = 0; i < size[0];i++) {
    for (int j = 0; j < size[1];j++) printf("%c ", Final[i][j]);
    printf("\n");
  }
  getch();
}
int getDepth(float*** Scenes, int* size, int i, int j) {
  for (int k = 0; k < size[2]; k++) if (Scenes[k][i][j] != 0) return 'O';
  return ' ';
}
int** PreProcess(int* size, int n, ...) {
  va_list ptr; va_start(ptr, n);
  float*** Scenes = malloc(n * sizeof(float**));
  int** final = malloc(size[0] * sizeof(int*));
  int* sizeCube = Vector3d(size[0], size[1], n);
  for (int i = 0; i < n; i++) Scenes[i] = va_arg(ptr, float**);
  for (int i = 0; i < size[0]; i++) {
    final[i] = malloc(size[1] * sizeof(int));
    for (int j = 0; j < size[1]; j++) final[i][j] = getDepth(Scenes, sizeCube, i, j);
  }
  return final;
}