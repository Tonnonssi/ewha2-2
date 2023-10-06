#include <stdio.h>

int main()
{   
    int arr[10];
    int n=0;
    
    for (int i=0; i <10; i++){
        printf("index: %d :", n);
        arr[n++] = i;
        printf("%d\n",arr[i]);
    }
    return 0;
}
