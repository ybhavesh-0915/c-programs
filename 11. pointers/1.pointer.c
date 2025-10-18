#include <stdio.h>

int main(){
    int x = 5;
    
    
    int *ptr = &x;
    *ptr = 'A';
    printf("%p\n", ptr);
    printf("%d\n", *ptr);
    printf("%d\n", x);
    return 0;
}