#include <stdio.h>

int countDub(int arr[], int len) {
  int a[len];
  int lenA = 0, count = 0;
  for (int i = 0; i < len; i++) {
    int in = 0;
    for (int j = 0; j < lenA + 1;j++) {
      if (a[j] == arr[i]) {
        int in = 1;
        break;
      }
    }
    if (!in) {
      a[lenA++] = arr[i];
    }
  }
  for (int i = 0; i < len; i++) {
    printf("%d ", a[i]);
  }
  for (int i = 0; i < lenA;i++) {
    int time = 0;
    for (int j = 0; j < len;j++) {
      if (arr[j] == a[i]) {
        time++;
        break;
      }
    }
    if (time >= 2) count++;
  }
  return count;
}
int main() {
  int a[] = { 1,2,2,9,3,4 };
  int len = sizeof a / sizeof a[0];
  printf("%d", countDub(a, len));
}

