#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <math.h>

char* Shift(char*A, int x) {
	int i;
	char *B = malloc((strlen(A)+1)*sizeof(char));
	B[strlen(A)] = '\0';
	for (i = 0;i < strlen(A);i++) B[(i+x)%strlen(A)] = A[i];
	return B;
}

int main() {
	char A[1000], B[1000];
	gets(A);fflush(stdin);
	gets(B);fflush(stdin);
	printf("%s\n",Shift(A,strlen(A)-1));
	printf("%s\n",Shift(B,1));
}
