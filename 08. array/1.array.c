#include <stdio.h>
#define SIZE 4

void printArr(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d\n", arr[i]);
    }; 
    printf("\n");
}

int main(){

    int arr[]={1,2,3,4};
    printArr(arr, SIZE);

    int arr1[SIZE]; // garbage value
    printArr(arr1, SIZE);

    int arr2[SIZE] = {}; //{0,0,0,0}
    printArr(arr2, SIZE);

    int arr3[SIZE] = {0}; //{0,0,0,0}
    printArr(arr3, SIZE);

    int arr4[SIZE] = {1,2}; //{1,2,0,0}
    printArr(arr4, SIZE);


    int arr5[SIZE];
    printArr(arr1, SIZE+3);
    for(int i=0; i<SIZE; i++){
        printf("%s", "Enter the value: ");
        scanf("%d", &arr1[i]);
    };
    printArr(arr1, SIZE+3);
    printArr(arr, SIZE);

    return 0;
}
