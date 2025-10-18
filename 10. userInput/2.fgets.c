#include <stdio.h>
int main()
{
    char x[100];
    printf("enter name surname and age: ");
    fgets(x, sizeof(x), stdin); 

    char name[64];
    char surname[64];
    int age;

    sscanf(x, "%s %s %d", name, surname, &age);
    printf("your name is %s %s and age is %d\n", name, surname, age);
    return 0;
}