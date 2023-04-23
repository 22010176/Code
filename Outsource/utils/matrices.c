float* addMatricsf(float* a, float* b, int height, int width) {
  float* c = malloc(width * height * sizeof(float));
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width;j++) {
      *(c + i + j) = *(a + i + j) + *(b + i + j);
    }
  }
  return c;
}
void printMaxtrics(float* a, int height, int width) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%.2f ", *(a + i + j));
    }
    printf("\n");
  }
}