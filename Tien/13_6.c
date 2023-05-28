#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>
// 65 - A
// 97 - a
char* Encode(char* B, int x) {
	int i;
	char* A = malloc((strlen(B) + 1) * sizeof(char));
	A[strlen(B)] = '\0';
	for (i = 0; i < strlen(B);i++) {
		if (B[i] <= 91) A[i] = ((B[i] - 65) + x) % 26 + 65;
		else A[i] = ((B[i] - 97) + x) % 26 + 97;
	}
	return A;
}
char* Decode(char* B, int x) {
	int i;
	char* A = malloc((strlen(B) + 1) * sizeof(char));
	A[strlen(B)] = '\0';
	for (i = 0; i < strlen(B);i++) {
		if (B[i] <= 91) A[i] = (B[i] - 65) - x + 26 + 65;
		else A[i] = B[i] - x + 26 + 97;
	}
	return A;
}
int main() {
	char A[1000], B[1000];
	gets(A);fflush(stdin);
	gets(B);fflush(stdin);
	int n;
	scanf("%d", &n);
	printf("%s\n", Encode(A, n));
	printf("%s\n", Decode(A, n));
}
