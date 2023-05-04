#include <stdio.h>
int check(int arr[], int ite, int len) {
  for (int i = 0; i < len; i++)
    if (arr[i] == ite) return 1;
  return 0;
}
int check2(int arr[], int ite, int len) {
  for (int i = 0, c = 0; i < len; i++) {
    if (arr[i] == ite) c++;
    if (c == 2) return 1;
  }
  return 0;
}
int countDub(int arr[], int len) {
  int a[len], a_len, count = 0;
  for (int i = 0, c = 0; i < len; i++) {
    if (check(a, arr[i], c + 1)) continue;
    a[c++] = arr[i];
    a_len = c;
  }
  for (int i = 0; i < a_len; i++) {
    if (check2(arr, a[i], len)) ++count;
  }
  return count;
}
int main() {
}

