#include <stdio.h>

/*
    typedef sirf compiler ko ek naya naam (alias) deta hai kisi existing type ke liye.
    compiler kabhi bhi is line pe memory allocate nahi karta,
    kyunki yeh line koi variable declare nahi karti — bas ek type rename karti hai
*/

typedef struct info{
    int std;
    int roll;
    int monthly_fees;
    int annual_fees;
}info1, info2, info3; //multiple type rename

typedef struct student{
    char name[64];
    int age;
    info1 i;
}student, stud1, stud2;


/*
if you are using typedef the anomonys struct enum union cannot created
*/

typedef struct {
    int data;
    int rediredt;
}node;

typedef int myint, yourint; 
// typedef unsigned short myint usn1, usn2; //invalid A typedef statement cannot mix an existing typedef name in its base type part.
typedef myint usn1, usn2; // yeah valid hai

// unsigned short myint a = b through error

/*
Redefinition with same type → allowed
typedef int myint;
typedef int myint;   // redundant, allowed
typedef int myint;   // still allowed

Redefinition with different type → not allowed
typedef int myint;
typedef unsigned short myint;  // ❌ ERROR compile time error 
*/

/*
    pointer
*/
typedef int *ptr;
typedef ptr *ptrs ; //valid hai 

/*
array
*/

typedef int arr[];
arr datas ={1,2,3,4};

typedef int arr1[5];
arr1 how = {1,2,3,4,5};


int main(){
    typedef unsigned short int usn; //here usn is not variable 
    usn num = 5;
    const usn num2 = 10;

    printf("%hu", num);
    printf("%hu", num2);

    node n1;
    n1.data = 1;
    n1.rediredt = 2;

    myint data;
    ptr p = &data;
    ptr *p1 = &p; // double pointer 
}