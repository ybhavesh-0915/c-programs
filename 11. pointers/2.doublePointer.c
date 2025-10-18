#include <stdio.h>

int main(){
    int x = 5;
    int y = 10;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;
    *ptr2 = &y;

    printf("addres of variable x is %p\n", &x);
    printf("addres of variable y is %p\n", &y);
    printf("address contain by ptr1 is %p\n", ptr1);
    printf("the address of ptr1 is %p\n", &ptr1);

    printf("address contain by ptr2 is %p\n", ptr2);
    printf("the address of ptr2 is %p\n", &ptr2);
    printf("*ptr2 is %p\n", *ptr2);
    printf("**ptr2 is %d\n", **ptr2);
    return 0;
}