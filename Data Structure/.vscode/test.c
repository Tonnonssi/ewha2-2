#include <stdio.h>

// 함수 선언
int factorial(int n);

int main() {
    int num;
    printf("팩토리얼을 계산할 양의 정수를 입력하세요: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("음수의 팩토리얼은 정의되지 않습니다.\n");
    } else {
        int result = factorial(num);
        printf("%d의 팩토리얼은 %d입니다.\n", num, result);
    }

    return 0;
}

// 팩토리얼 계산 함수
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
