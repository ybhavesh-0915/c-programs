#include <stdio.h>


int main(){
    int x;
    printf("enter the value: ");
    scanf("%d", &x);

    if(x==1){
        printf("if chala\n");
    }
    else if(x==2){
        printf("else if chala\n");
    }
    else{
        printf("else chala\n"); 
    }
    return 0;
}