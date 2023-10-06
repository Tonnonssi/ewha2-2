#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct {
    int row;
    int col;
    int value;
}element;

typedef struct 
{
    element data[MAX_TERMS];
    // define the size of matrix
    int rows;
    int cols;
    int terms;
}SparseMatrix;

SparseMatrix add_sparse_matrix(SparseMatrix a, SparseMatrix b)
{
    SparseMatrix c;
    int ca=0, cb=0, cc=0;  // index of each element
    if (a.rows != b.rows || a.cols != b.cols){ // 예외처리
        fprintf(stderr," Size error in Sparse matrix \n"); 
        exit(1);
    }
    c.rows = a.rows; // 전부 다 3x3 행렬을 기준으로 하기 때문에 그냥 a
    c.cols = a.cols;
    c.terms = 0; 

    while(ca < a.terms && cb < b.terms){
        int inda = a.data[ca].row * a.cols + a.data[ca].col; // row*(cols=3) + col 안 겹쳐용 그냥 순서대로 쭉됨
        int indb = b.data[cb].row * b.cols + b.data[cb].col;

        if (inda < indb){
            c.data[cc++] = a.data[ca++]; 
        }

        else if (inda == indb){
            if ((a.data[ca].value + b.data[cb].value) != 0){
                c.data[cc].row = a.data[cc].row;
                c.data[cc].col = a.data[cc].col;
                c.data[cc].value = a.data[ca].value + b.data[cb].value;
            }
            else ca++; cb ++;
        }
        else c.data[cc++] = b.data[cb++];
    }

    for (;ca<a.terms;) c.data[cc++] = a.data[ca++];
    for (;cb<b.terms;) c.data[cc++] = b.data[cb++];

    c.terms = cc;
    return c;
}

int main(){
    SparseMatrix m1 = {{0,0,1}, {0,2,3}, {2,1,2}, 3,3,3};
    SparseMatrix m2 = {{0,1,1}, {2,2,1}, 3,3,2};
    SparseMatrix m3;
    m3 = add_sparse_matrix(m1,m2);
    return 0;
}