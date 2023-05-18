#include "hea.h"
#include "arr.c"

float** createMatrix(int* size);
float** createMatrix2(int collumns, int rows);
static int findIndent(float** A, int* size);
void printMaxtric(float** A, int* size);
float* Vector2f(float x, float y);
int* Vector2d(int x, int y);
void freeMatrix(float** A, int* size);
float** ReplaceMatrix(float** Des, float** S, int* size);
float** copyMatrix(float** A, int* size);

float** FillMatrix(float** A, int* size, float (*func)(int, int));
float** FillMatrixFunc1(float** A, int* size, float(*func)(int));
float** FillMatrixFunc2(float** A, int* size, float(*func)(int));

float** MatrixMultiply(float** A, float** B, int* size1, int* size2);
float** MatrixAddition(float** A, float** B, int* size);
float Descartes(int i, int j);
float** DescartesMatrix(int size);
float** I1(int size, int* swap);
float** I2(int size, float time, int line);
float** I3(int size, float time, int* line);
float** TriangularMatrix(float** A, int* size);
float Determinant(float** A, int size);
float** Transpose(float** A, int* size);
int CompareMatrix(float** A, float** B, int* size);
float** ScalarMultiply(float** A, int* size, float scale);
int* Vector3d(int x, int y, int z);

#if __INCLUDE_LEVEL__ == 0
float A_(int i, int j) { return i + j; }
float B_(int i, int j) { return (i + 1) * (j + 1); }
int main() {}
#endif

float Descartes(int i, int j) { return i == j; }
float** MatrixMultiply(float** A, float** B, int* size1, int* size2) {
  float** R = createMatrix2(size1[0], size2[1]);
  if (size1[1] != size2[0]) return NULL;
  for (int i = 0; i < size1[0];i++)
    for (int j = 0; j < size2[1];j++) {
      R[i][j] = 0;
      for (int k = 0; k < size1[1];k++) R[i][j] += A[i][k] * B[k][j];
    }
  return R;
}
float** MatrixAddition(float** A, float** B, int* size) {
  float** C = createMatrix(size);
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) C[i][j] = A[i][j] + B[i][j];
  return C;
}
static float _(int _1, int _2) { return rand() % 100; }
float** FillMatrix(float** A, int* size, float(*func)(int, int)) {
  if (func == NULL) func = _;
  // printf("%f", func(4, 5));
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) A[i][j] = func(i, j);
  return A;
}
float** FillMatrixFunc1(float** A, int* size, float(*func)(int i)) {
  for (int i = 0; i < size[1]; i++) {
    int res = round(func(i));
    for (int j = 0; j < size[0]; j++) A[j][i] = (size[0] - res) == j;
  }
  return A;
}
float** FillMatrixFunc2(float** A, int* size, float(*func)(int i)) {
  for (int i = 0; i < size[0]; i++) {
    int res = round(func(i));
    for (int j = 0; j < size[1]; j++) A[i][j] = res == j;
  }
  return A;
}
float** copyMatrix(float** A, int* size) {
  float** B = createMatrix(size);
  for (int i = 0; i < size[0];i++)
    for (int j = 0; j < size[1];j++) B[i][j] = A[i][j];
  return B;
}
void freeMatrix(float** A, int* size) {
  for (int i = 0; i < size[0]; i++) free(A[i]);
  free(A);
}
float** ReplaceMatrix(float** Des, float** S, int* size) {
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) Des[i][j] = S[i][j];
  freeMatrix(S, size);
  return Des;
}
float** createMatrix(int* size) {
  float** A = malloc(size[0] * sizeof(float*));
  for (int i = 0; i < size[0]; i++) A[i] = malloc(size[1] * sizeof(float));
  return A;
}
float** createMatrix2(int collumns, int rows) {
  float** A = malloc(collumns * sizeof(float*));
  for (int i = 0; i < collumns; i++) A[i] = malloc(rows * sizeof(float));
  return A;
}
static int findIndent(float** A, int* size) {
  float* max = malloc(size[0] * sizeof(float));
  for (int i = 1; i < size[0]; i++) max[i] = A[i][findAbsMax(A[i], size[1])];
  int result = ceil(log10(max[findAbsMax(max, size[0])])) + 4;
  if (result < 0) result = 10;
  return result;
}
void printMaxtric(float** A, int* size) {
  int indent = findIndent(A, size);
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) printf("|%*.2lf", indent, A[i][j]);
    printf("\n");
  }
  printf("\n");
}
float* Vector2f(float x, float y) {
  float* vec = malloc(2 * sizeof(float));
  vec[0] = x; vec[1] = y;
  return vec;
}
int* Vector2d(int x, int y) {
  int* vec = malloc(2 * sizeof(int));
  vec[0] = x; vec[1] = y;
  return vec;
}
int* Vector3d(int x, int y, int z) {
  int* vec = malloc(3 * sizeof(int));
  vec[0] = x; vec[1] = y; vec[2] = z;
  return vec;
}
float** DescartesMatrix(int size) {
  int* sizeI = Vector2d(size, size);
  return FillMatrix(createMatrix(sizeI), sizeI, Descartes);
}
float** I1(int size, int* swap) {
  float** I = DescartesMatrix(size);
  I[swap[0]][swap[0]] = 0; I[swap[1]][swap[1]] = 0;
  I[swap[0]][swap[1]] = 1; I[swap[1]][swap[0]] = 1;
  return I;
}
float** I2(int size, float time, int line) {
  float** I = DescartesMatrix(size);
  I[line][line] = time;
  return I;
}
float** I3(int size, float time, int* line) {
  float** I = DescartesMatrix(size);
  I[line[0]][line[1]] = time;
  return I;
}
float** TriangularMatrix(float** A, int* size) {
  int* sizeI = Vector2d(size[0], size[0]), min = size[0] > size[1] ? size[1] : size[0];
  float** B = copyMatrix(A, size), ** I = DescartesMatrix(size[0]);
  for (int i = 0; i < min;i++) {
    float** I_ = copyMatrix(I, sizeI);
    if (B[i][i] == 0) {
      for (int j = i + 1; i < size[0];j++) {
        if (B[i][j] == 0) continue;
        float** I_2 = I1(size[0], Vector2d(j, i));
        ReplaceMatrix(B, MatrixMultiply(I_2, B, sizeI, size), size);
        freeMatrix(I_2, sizeI);
        break;
      }
      continue;
    }
    for (int j = i + 1; j < size[0];j++) I_[j][i] = -B[j][i] / B[i][i];
    ReplaceMatrix(B, MatrixMultiply(I_, B, sizeI, size), size);
    freeMatrix(I_, sizeI);
  }
  freeMatrix(I, sizeI);
  return B;
}
float Determinant(float** A, int size) {
  int* sizeB = Vector2d(size, size);
  float** B = TriangularMatrix(A, sizeB);
  float res = 1;
  for (int i = 0; i < size;i++) res *= B[i][i];
  freeMatrix(B, sizeB); free(sizeB);
  return res;
}
float** ScalarMultiply(float** A, int* size, float scale) {
  float Func(int  i, int j) { return A[i][j] * scale; }
  return FillMatrix(createMatrix(size), size, Func);
}
float** Transpose(float** A, int* size) {
  float F(int i, int j) { return A[j][i]; }
  int* sizeT = Vector2d(size[1], size[0]);
  float** R = FillMatrix(createMatrix(sizeT), sizeT, F);
  free(sizeT);
  return R;
}
int CompareMatrix(float** A, float** B, int* size) {
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) if (A[i][j] != B[i][j]) return 0;
  return 1;
}