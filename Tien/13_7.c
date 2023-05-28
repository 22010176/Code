#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

void Shift(char* A, int x) {
	int i;
	char B[strlen(A)];
	for (i = 0;i < strlen(A);i++) B[(i + x) % strlen(A)] = A[i];
	printf("%s\n", B);
}

int main() {
	char A[1000], B[1000];
	gets(A);fflush(stdin);
	gets(B);fflush(stdin);
	Shift(A, strlen(A) - 1);
	Shift(B, 1);
}
