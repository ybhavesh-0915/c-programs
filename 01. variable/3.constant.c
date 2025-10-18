#include <stdio.h>

int main(){
    const int NUM = 5;
    //NUM = 6; //error

    char str0;
    scanf("%c", &str0);
    const char str = str0;
    printf("%d", NUM);
    printf("%c", str);
}