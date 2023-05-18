#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <string.h>
int (*Func2(int* x))(int, int) {
    int a = *x;
    int A(int i, int j)
    {
        return a * i + j;
    }
    return A;
}
int b(int (*A)(int, int))
{
    printf("%d\n", A(8, 3));
    printf("%d\n", A(3, 4));
    printf("%d\n", A(8, 3));
}
// int Func3
int main() {
    char a[] = "a";
    char b[] = "b";
    printf("%d", strcmp(a, b));
}