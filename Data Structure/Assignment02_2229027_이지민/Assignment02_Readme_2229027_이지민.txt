# 01. Transpose Sparse Matrix
## introduction
spare matrix를 전치하는 코드다. 확인을 위해 dense matrix형태로 반환해 출력한다. 

## structure
1. num_of_col에 기존 행렬의 특정 열에 몇 개의 요소들이 들어 있는지 넣는다. 열의 인덱스는 list의 인덱스와 동일하다. 
2. row_idx에는 전치 행렬에서 각 행(전치 전 열)이 sparse matrix에서 몇 번째 요소인지 들어있다. 이전의 행의 시작점과 이전 행의 요소 개수를 더한다. 
3. 전치 전의 sparse matrix를 순서대로 지나가며 row_idx를 바탕으로 idx를 정한다. 이미 지나간 row_idx에는 1을 더해, 한 행에 여러 인덱스가 있을 때를 대비한다. 

## function
1. transposeMatrix(SparseMatrix B) return B_T : 입력받은 행렬을 전치시켜 반환시킨다. 
2. printDenseMatrix(SparseMatrix m) return X, print문을 이용해 두 행렬을 Dense꼴로 프린트한다. 

## how to run
전치시키고 싶은 행렬을 main함수 안에서 변경해준다. {행렬, 행의 개수, 열의 개수, 요소의 개수}
코드를 컴파일고 실행한다. 
Dense Matrix꼴로 전치 전 행렬 B와 전치된 행렬 B_T를 출력한다. 

# 02. Allocate, Add, and Deallocate Matrix
## introduction
동적 메모리를 할당해 행렬을 표현한다. 이 방식을 사용한 두 개의 행렬을 더하고, 동적 메모리 할당을 끝낸다. 

## functions
1. mem_alloc_3D_double() return matrix의 시작 주소 : 동적 메모리를 할당하는 함수 
2. addition_3D(input matrix1, input matrix2, output matrix) return X, print로 계산결과를 반환한다. 
동적 메모리가 할당된 두 행렬을 더하는 함수
3. deallocate_3D_double(matrix의 시작 주소) return X, 동적 메모리를 거둬간다. 
4. assignMatrix (matrix의 시작 주소) : return X, scanf를 이용해 행렬을 입력받는다. 

## how to run
프로그램을 컴파일하고 실행한다. 
먼저 행렬의 크기를 x y z꼴로 작성한다. 
행렬 A,B의 요소를 하나씩 할당하면 된다. 
요소 할당을 끝내면 자동으로 덧셈 결과가 나온다. 




