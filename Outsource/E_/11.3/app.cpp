#include <bits/stdc++.h>

using namespace std;
typedef struct {
    float x; float y;
} Vector2;

int** CreateMat(Vector2 *size);
int main(){
    vector <int> A;
    for (int i  =0 ; i<= 90;i++) {
        A.push_back(i);
    }
    for (int i = 0; i < A.size();i++) {
        cout << A[i] << " ";
        if ((i+1) % 15 == 0) cout << endl;
    }
    // Vector2 size = {5,6};
    // int ** A = CreateMat(&size);
    
    
}
int** FillMat(int *size,int (*A)(int i,int j,int n, ...),...){
    return NULL;
}
int** CreateMat(Vector2 *size) {
    int ** A =(int**) malloc(size->x * sizeof(int*));
    for (int i =0; i < size->x; i++) A[i] = (int*) malloc(size->y * sizeof(int));
    return A;
}