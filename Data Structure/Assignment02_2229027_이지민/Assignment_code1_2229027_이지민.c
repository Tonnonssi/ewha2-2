#include <stdio.h>
#define MAX_TERMS 101

typedef struct
{
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix // SparseMatrix의 구조 정의
{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

SparseMatrix transposeMatrix(SparseMatrix B) // 행렬을 전치하는 코드 
{
    SparseMatrix B_T;
    int num_of_col[B.cols]; // num_of_col : 행렬의 col에 있는 요소 개수를 저장하는 arr
    int row_idx[B.cols]; // 전치 행렬 각 row의 시작 위치를 저장하는 arr
    int i = 0; 
    int n, idx;

    for (i = 0; i < B.cols; i++) num_of_col[i] = 0; // num_of_col를 초기화


    for (i = 0; i < B.terms; i++) // num_of_col을 만드는 코드
    {
        n = B.data[i].col;
        num_of_col[n]++;
    }

    // row_idx를 만드는 코드
    row_idx[0] = 0;
    for (i = 1; i < B.cols; i++)
    {
        row_idx[i] = row_idx[i - 1] + num_of_col[i - 1];
    }

    // B_T의 기본 골격을 만들어줌
    B_T.rows = B.cols;
    B_T.cols = B.rows;
    B_T.terms = B.terms; // terms : sparse matrix의 value 총 개수

    for (i = 0; i < B.terms; i++) // B를 순서대로 훑으면서 row_idx에 따라 배치함 
    {
        n = B.data[i].col; // 기존의 col num
        idx = row_idx[n]; // 기존의 col num에 따른 전치 행렬에서의 위치

        B_T.data[idx].value = B.data[i].value;
        B_T.data[idx].col = B.data[i].row;
        B_T.data[idx].row = B.data[i].col;
        row_idx[n]++;
    }
    return B_T;
}

void printDenseMatrix(SparseMatrix m) // SparseMatrix -> DenseMatrix
{
    int cnt = 0;
    int ncol = m.cols;
    int nrow = m.rows;

    while (cnt < m.terms) // SparseMatrix에 명시되어 있는 위치값을 바탕으로 Dense Matrix를 만드는 코드 
    {
        for (int i=0; i<nrow; i++)
        {
            for(int j=0; j<ncol; j++)
            {
                if (i == m.data[cnt].row && j == m.data[cnt].col) 
                {
                    printf("%d", m.data[cnt].value);
                    cnt ++;
                }
                else printf("%d", 0);
            }
            printf("\n");
        }
    }
}

int main()
{
    SparseMatrix B = {{{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}}, 6, 6, 7};
    SparseMatrix B_T = transposeMatrix(B); // 전치된 행렬을 저장

    printf("Matrix B:\n"); // B를 출력
    printDenseMatrix(B);
    printf("Transpose of B:\n");
    printDenseMatrix(B_T); // B_T를 출력
    return 0;
}
