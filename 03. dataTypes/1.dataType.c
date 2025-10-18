#include <stdio.h>

/*

    int ---- 4B ---- %d or %i
    float ---- 4B ---- %f
    double ---- 8B ---- %lf
    short int ---- 2B ---- %hd
    unsigned int ---- 4B ---- %u
    unsigned short int ---- 2B ---- %hu
    long int ---- 8B ----- %ld
    long long int ----- 8B ---- %lld
    long double ---- 16B ----- %LF

    char ---- 1B ---- %c
    string -----[size] ---- %s

    size ---- %zu
    pointer ---- %p

*/
int main()
{

    int num1 = 5;
    float num2 = 10.545678;
    double num3 = 100.32561;
    short int num4 = 125;
    unsigned int num5 = 1254;
    unsigned short int num6 = 12;
    long int num7 = 15;
    long long int num8 = 152478;
    long double num9 = 12345679;

    char alpha = 'A';
    char str[5] = "Hello";

    int *ptr = &num1;

    printf("int %d \n", num1);
    printf("float %f\n", num2);
    printf("double %lf\n", num3);
    printf("short %hd\n", num4);
    printf("unsigned %u\n", num5);
    printf("unsigned short %hu\n", num6);
    printf("long %ld\n", num7);
    printf("long long %lld\n", num8);
    printf("long double %LF\n", num9);
    printf("char %c\n", alpha);
    printf("string %s\n", str);
    printf("pointer %p\n", ptr);

    printf("int %zu\n", sizeof(num1));
    printf("float %zu\n", sizeof(num2));
    printf("double %zu\n", sizeof(num3));
    printf("short %zu\n", sizeof(num4));
    printf("unsigned %zu\n", sizeof(num5));
    printf("unsigned short %zu\n", sizeof(num6));
    printf("long %zu\n", sizeof(num7));
    printf("long long %zu\n", sizeof(num8));
    printf("long double %zu\n", sizeof(num9));
    printf("char %zu\n", sizeof(alpha));
    printf("string %zu\n", sizeof(str));
    printf("pointer %zu\n", sizeof(ptr));
}