#include <stdio.h>

union myunion1{
    int num1;
    float num2;
    char str[64];
};

union myunion2{
    int num1;
    double num2;
    union myunion1 s1;
};

int main(){

    union myunion1 u1;
    u1.num1 = (int)3.142;


    union myunion2 u2;
    u2.s1 = u1;
    u2.s1.num2 = 3.142567;
    printf("%f\n",u2.s1.num2);
    printf("%zu\n", sizeof(u2));

    union myunion2 *unionptr = &u2;
    printf("acess using pointer-------\n");
    printf("%f\n", unionptr->s1.num2);
    printf("%f\n", (*unionptr).s1.num2);

    
    
    return 0;
}