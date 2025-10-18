#include <stdio.h>

int main(){
    int num = 5;    //4 bytes
    char alpha = 'A'; //1 bytes
    float num1 = 5.956; //4 bytes
    double num2 = 5.64648546; //8bytes

    printf("%d, %c, %f, %.15lf\n", num, alpha, num1, num2);
    return 0;
}