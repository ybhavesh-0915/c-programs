#include <stdio.h>

int main(){
    char str1 = 'A';
    char str2 = 'B';
    char strAnd = str1 | str2; //64|65
    printf("strAnd = %c\n", strAnd);

    int a = -5; //(0101)
    unsigned int b = 9; //(1001)
    unsigned int and = a & b;
    unsigned int or = a | b;
    unsigned int xor = a^b;
    unsigned int ls = a<<1;
    unsigned int rs = a>>3;

    printf("a&b = %u\n", and);
    printf("a|b = %u\n", or);
    printf("a^b = %u\n", xor);
    printf("a<<1 = %u\n", ls);
    printf("a>>3 = %u\n", rs);

    int x;
    for(int i=1; i<=4; i++){
        x = (a>>(4-i)) & 1;
        printf("x = %u\n", x);
    }

    return 0;
}