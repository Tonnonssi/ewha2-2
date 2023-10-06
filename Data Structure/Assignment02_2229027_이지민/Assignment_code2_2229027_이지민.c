#include <stdio.h>
#include <stdlib.h>

// 행렬의 dim을 저장
int x, y, z = 0;

// 3D array에 동적 메모리를 할당한다. 
double ***mem_alloc_3D_double() {
    double ***m = (double ***)malloc(sizeof(double **) * x); 
    for (int i = 0; i < x; i++) {
        m[i] = (double **)malloc(sizeof(double *) * y);
        for (int j = 0; j < y; j++) {
            m[i][j] = (double *)malloc(sizeof(double) * z);
        }
    }
    return m;
}
// 두 개의 3D 행렬을 더한다. 
void addition_3D(double ***input1, double ***input2, double ***output) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int q = 0; q < z; q++) {
                output[i][j][q] = input1[i][j][q] + input2[i][j][q];
                printf("matrix[%d][%d][%d] = %f\n", i, j, q, output[i][j][q]);
            }
        }
    }
    printf("\n");
}
/// 할당한 메모리를 지운다. 
void deallocate_3D_double(double ***m) {
    if (m != NULL) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                free(m[i][j]);
            }
            free(m[i]);
        }
        free(m);
        m = NULL;
    }
}
// 행렬을 만드는 함수 
void assignMatrix(double ***m) {
    int count = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int q = 0; q < z; q++) {
                printf("matrix[%d][%d][%d] = ", i, j, q);
                scanf("%lf", &m[i][j][q]);
            }
        }
    }
}

int main() {
    // 행렬을 정의한다. 
    printf("input x, y, z (format = x y z): ");
    scanf("%d %d %d", &x, &y, &z);

    double ***A = mem_alloc_3D_double();
    double ***B = mem_alloc_3D_double();
    double ***C = mem_alloc_3D_double();

    // 두 개의 행렬을 만든다. 
    printf("Matrix A\n");
    assignMatrix(A);
    printf("Matrix B\n");
    assignMatrix(B);

    printf("\n");
    // 행렬의 덧셈
    addition_3D(A, B, C);

    // 할당된 메모리를 거둬간다. 
    deallocate_3D_double(A);
    deallocate_3D_double(B);
    deallocate_3D_double(C);

    return 0;
}
