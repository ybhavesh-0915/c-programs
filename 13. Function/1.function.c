#include <stdio.h>

int naturalSum(int); //declaration
int factorial(int);
int ascii(char);

int main(){
    printf("%d\n", naturalSum(5));
    printf("%d\n", factorial(1));
    printf("%d\n", ascii('a'));
}

int naturalSum(int n){ //defination
    int num = n;
    if(num != 0){
        return num + naturalSum(n-1);
    }else{
        return 0;
    }
}

int factorial(int num){
    if(num > 0){
        return num * factorial(num -1);
    }
    else{
        return 1;
    }
}

int ascii(char str){
    int code = (int)str;
    return code;
}