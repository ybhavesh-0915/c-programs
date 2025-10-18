#include <stdio.h>

/*
In C, the static keyword changes the storage duration and/or visibility (scope) of a variable or function.
It can be applied to:

Local variables inside a function

Global variables

Functions

So static can affect both how long something lives in memory and where it can be accessed from.
*/
void counter(){
    static int count = 0;
    printf("%d\n", count);
    count++;
}
int main(){
    counter(); //0
    counter(); //1
    counter(); //2
    counter(); //3
    counter(); //4
}