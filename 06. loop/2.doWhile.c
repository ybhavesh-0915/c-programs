#include <stdio.h>

int main(){

    int i = 10;

    do{
        printf("%d\n",i);
    }while(i<10);

    printf("second do loop\n");
    i=0;
    do{
        printf("%d\n",i);
        i++;
    }while(i<10);

    return 0;
}