#include <stdio.h>

int main(){

    int arr[4]={4,5,6,7};
    printf("method1 : arr[i]\n");
    for(int i=0; i<4; i++){
        printf("The address of arr[%d] is %p and value %d\n", i, &arr[i], arr[i]);
    }

    printf("method1 : arr+i\n");
    for(int i=0; i<4; i++){
        printf("The address of (arr+%d) is %p and value %d\n", i, (arr+i), *(arr+i));
    }

    int *arrptr = arr;
    printf("method1 : arrptr[i]\n");
    for(int i=0; i<4; i++){
        printf("the address of arr[%d] using pointer is %p and value is %d\n",i, &arrptr[i], arrptr[i]);
    }
    printf("method1 : arrptr+i\n");
    for(int i=0; i<4; i++){
        printf("the address of arr[%d] using pointer is %p and value is %d\n", i, (arrptr+i), *(arrptr+i));
    }

    // 2d array

    return 0;
}