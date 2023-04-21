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