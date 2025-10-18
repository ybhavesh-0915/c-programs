#include <stdio.h>
#include <stdlib.h>

int *ascii(char* , int);
int *arrfunc();
int main(){
    char arr[6]={'A','{','C','D','E','\0'};
    int *asciiCode = ascii(arr, 5);
    for (int i = 0; i < 5; i++){
        printf("%d\n",asciiCode[i]);
    }

    int *myarr = arrfunc();
    for (int i = 0; i < 5; i++){
        printf("%d\n",myarr[i]);
    }
    
    return 0;
}

int *ascii(char *str, int size){
    int *arr = malloc(size * sizeof(size)); //created in heap memory not in stack
    for(int i=0; i<size; i++){
        arr[i]=str[i];
    }
    return arr;
}

int *arrfunc(){
    static int arr[5] = {10,11,12,13,45}; //created in data segment(not register) not in stack
    return arr;
}