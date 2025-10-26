#include <stdio.h>

/*
    typedef sirf compiler ko ek naya naam (alias) deta hai kisi existing type ke liye.
    compiler kabhi bhi is line pe memory allocate nahi karta,
    kyunki yeh line koi variable declare nahi karti — bas ek type rename karti hai
*/



int main(){
    typedef unsigned short int usn; //here usn is not variable 
    usn num = 5;
    const usn num2 = 10;

    printf("%hu", num);
    printf("%hu", num2);
}