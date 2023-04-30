#include "hea.h"
#include "arr.c"

float** createMatrix(int* size);
float** createMatrix2(int collumns, int rows);
static int findIndent(float** A, int* size);
void printMaxtric(float** A, int* size);
float* Vector2f(float x, float y);
int* Vector2d(int x, int y);
void freeMatrix(float** A, int* size);
void ReplaceMatrix(float** A, float** B, int* size);
float** copyMatrix(float** A, int* size);
void FillMatrix(float** A, int* size, float (*f)(int, int));
float** MatrixMultiply(float** A, float** B, int* size1, int* size2);
float** MatrixAddition(float** A, float** B, int* size);
float Descartes(int i, int j);

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
void FillMatrix(float** A, int* size, float(*f)(int, int)) {
  if (f == NULL) f = _;
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) A[i][j] = f(i, j);
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
void ReplaceMatrix(float** Des, float** S, int* size) {
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) Des[i][j] = S[i][j];
  freeMatrix(S, size);
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
  int result = ceil(log10(max[findAbsMax(max, size[0])]));
  return result + 4;
}
void printMaxtric(float** A, int* size) {
  int indent = findIndent(A, size);
  if (indent < 0) indent = 15;
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) printf("|%*.2lf", indent, A[i][j]);
    printf("\n");
  }
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