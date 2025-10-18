#include <stdio.h>
#define SIZE 5

int main(){

    int arr[SIZE] = {1,2,3,4};
    printf("%zu\n", sizeof(arr)); //20

    int arr1[0]={};
    printf("%zu\n", sizeof(arr1)); 

    return 0;
}