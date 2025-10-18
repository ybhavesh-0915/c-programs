#include <stdio.h>

int main(){

    for (int i = 0; i < 10; i++){
        printf("loop chala\n");
        if (i==5){
            printf("if block hai\n");
            break;
        };
    }

    for(int j=0; j<5; j++){
        break;
        printf("J = %d\n", j);
    }
    printf("katam\n");
    return 0;
}