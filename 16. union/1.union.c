#include <stdio.h>
#include <string.h>
/*
    direct copy of union is allowed but both belong to same union
*/
union{ //anomynus union
    int age;
    char name[15];
}u1,u2,u3;

union myunion{
    int num;
    char str[25];
};

int main(){
    u1.age = 64;
    strcpy(u1.name, "bhavesh"); //union u1 have no longer int type memory
    u2=u1;
    printf("%s\n", u1.name);
    printf("%s\n", u2.name);

    union myunion s1, s2;
    strcpy(s1.str, "bhavesh");
    s1.num = 25;
    // s2 = u1; throws error
    s2 = s1; // but only num will copied
    printf("%d\n", s1.num);
    return 0;
}

