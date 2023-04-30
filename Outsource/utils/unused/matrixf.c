#include "../hea.h"
#include "../array/arrf.c"

void printMaxtric(float** a, int* size);
void printMaxtrics2(float** a, int x, int y);
void ReplaceMatrix(float** A, float** B, int* size);
void freeMatrix(float** A, int* size);
float* Vector2(float x, float y);
float** createMatrix(int* size);
float** createMatrix2(int collumns, int rows);
float** copyMatrix(float** A, int* size);
float** MatrixMultiply(float** A, float** B, int* size1, int* size2);
float** DecartMatrix(int size);
float** MatrixAddition(float** A, float** B, int* size);
float** I1(int size, float time, int* swap);
float** I2(int size, float time, int line);
float** I3(int size, float time, int* line);
void AutoFillMatrix(float** A, int* size);
float** ZeroSquare(int size);
float** CutMatrix(float** A, int* size, int* pos);

float** CutMatrix(float** A, int* size, int* pos) {
  float** B = createMatrix(Vector2(size[0] - 1, size[1] - 1));
  for (int i = 0, c1 = 0; i < size[0]; i++) {
    if (i == pos[0]) { c1++; continue; }
    for (int j = 0, c2 = 0; j < size[1]; j++) {
      if (j == pos[1]) { c2++; continue; }
      B[i - c1][j - c1] = A[i][j];
    }
  }
  return B;
}
float** ZeroSquare(int size) {
  float** I = createMatrix2(size, size);
  for (int i = 0; i < size; i++) for (int j = 0;j < size; j++) I[i][j] = 0;
  return I;
}
void AutoFillMatrix(float** A, int* size) {
  for (int i = 0; i < size[0]; i++) for (int j = 0; j < size[1]; j++) A[i][j] = (float)(rand() % 100);
}
void freeMatrix(float** A, int* size) {
  for (int i = 0; i < size[0]; i++) free(A[i]);
  free(A);
}
void ReplaceMatrix(float** A, float** B, int* size) {
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) A[i][j] = B[i][j];
  freeMatrix(B, size);
}
static int findIndent(float** A, int* size) {
  float* max = malloc(size[0] * sizeof(float));
  for (int i = 1; i < size[0]; i++) max[i] = findAbsMax(A[i], size[1]);
  int result = (int)ceil(log10(findAbsMax(max, size[0]) + 0.1));
  return result;
}
void printMaxtric(float** A, int* size) {
  int indent = findIndent(A, size);
  for (int i = 0; i < size[0]; i++) {
    for (int j = 0; j < size[1]; j++) printf("|%*.2lf", indent, A[i][j]);
    printf("\n");
  }
}
void printMaxtrics2(float** a, int x, int y) {
  int indent = findIndent(a, Vector2(x, y));
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) printf("|%*.2lf", indent, a[i][j]);
    printf("\n");
  }
}
float* Vector2(float x, float y) {
  float* size = malloc(2 * sizeof(float));
  size[0] = x; size[1] = y;
  return size;
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
float** copyMatrix(float** A, int* size) {
  float** B = createMatrix(size);
  for (int i = 0; i < size[0];i++)
    for (int j = 0; j < size[1];j++) B[i][j] = A[i][j];
  return B;
}
float** MatrixMultiply(float** A, float** B, int* size1, int* size2) {
  float** R = createMatrix2(size1[0], size2[1]);
  if (size1[1] != size2[0]) return NULL;
  for (int i = 0; i < size1[0];i++)
    for (int j = 0; j < size2[1];j++) {
      R[i][j] = 0;
      for (int k = 0; k < size1[1];k++) R[i][j] += (float)A[i][k] * (float)B[k][j];
    }
  return R;
}
float** DecartMatrix(int size) {
  float** I = createMatrix2(size, size);
  for (int i = 0; i < size;i++) for (int j = 0; j < size;j++) I[i][j] = i == j;
  return I;
}
float** MatrixAddition(float** A, float** B, int* size) {
  float** C = createMatrix(size);
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) C[i][j] = A[i][j] + B[i][j];
  return C;
}
float** I1(int size, float time, int* swap) {
  float** I = DecartMatrix(size);
  I[swap[0]][swap[0]] = 0; I[swap[1]][swap[1]] = 0;
  I[swap[0]][swap[1]] = 1; I[swap[1]][swap[0]] = 1;
  return I;
}
float** I2(int size, float time, int line) {
  float** I = DecartMatrix(size);
  I[line][line] = time;
  return I;
}
float** I3(int size, float time, int* line) {
  float** I = DecartMatrix(size);
  I[line[0]][line[1]] = time;
  return I;
}
