#include <stdio.h>

int main(){

    int x = 2;

    switch(x){
        case 1:{
            printf("%d\n", x);
            break;
        };
        case 2:{
            printf("%d\n", x);
            break;
        };
        default:{
            printf("default\n");
        };
    };

    char letter = 'A';

    switch(letter){
        case 'A':{
            printf("%c\n", letter);
            break;
        };
        case 'B':{ 
            printf("%c\n", letter);
            break; 
        };
        default:{
            printf("default\n");
        };
    }
    return 0;
}