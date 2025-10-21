#include <stdio.h>

/*
in c '{}' this has various meaning therfore we need to tell what type is this, is this an array or a structure or a code block
*/

void print_array(int *arr, int size){
    for(int i=0; i<size; i++){
        printf("%d\n", arr[i]);
    }
}

int main(){
    print_array((int[]){1,2,3,4}, 4);
    return 0;
}