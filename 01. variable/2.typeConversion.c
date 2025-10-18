#include <stdio.h>

void main(){
    int num = -300;    
    char alpha = num; //implicit conversion
    double num2 = 5.64648546;

    float x = (char)'A'; //explicit conversion

    printf("%d, %d, %.15lf\n", num, alpha, num2); //implicit conversion of char 
    printf("%f\n", x);
}