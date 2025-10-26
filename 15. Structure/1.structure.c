#include <stdio.h>
// member of the structure cannot be static but in c++ it is possible
// 1st struct don't hav tag name and student is call tagname

struct{ //anonymous structure
    char name; //members
    int age;
    int dob_year;
} s1, s2;

struct student{
    char name;
    int age;
    int doj;
    // static int doj; throw error in c but okk in c++;
}stud1, stud2;

int main(){
    s1.name = 'b';
    s1.age = 20;
    s1.dob_year = 2005;
    printf("name = %c \t age = %d \t dob year = %d\n", s1.name, s1.age, s1.dob_year);

    s2.name = 'r';
    s2.age = 21;
    s2.dob_year = 2004;
    printf("name = %c \t age = %d \t dob year = %d\n", s2.name, s2.age, s2.dob_year);

    stud1.name = 's';
    stud1.age = 20;
    stud1.doj = 2005;
    printf("name = %c \t age = %d \t doj = %d\n", stud1.name, stud1.age, stud1.doj);

    stud2.name = 't';
    stud2.age = 25;
    stud2.doj = 2065;
    printf("name = %c \t age = %d \t doj = %d\n", stud2.name, stud2.age, stud2.doj);

    struct student stud3 = {'a', 20, 2012};
    printf("name = %c \t age = %d \t doj = %d\n", stud3.name, stud3.age, stud3.doj);

    return 0;
}