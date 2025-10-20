#include <stdio.h>
#include <string.h>

struct student{
    int roll;
    char name[64];
    int age;
    int std;
    int monthly_fees;
    int annual_fees;
};

int main(){
    struct student s1 = {10641, "Bhavesh Yadav", 19, 14, 2000, 24000};
    struct student s2 = s1;

    s2.roll = 10639;
    strcpy(s2.name, "Justin Roy");

    printf("name = %s\t age = %d\t std = %d monthly fees = %d\t annual fees = %d\t roll no = %d\n", s1.name, s1.age, s1.std, s1.monthly_fees, s1.annual_fees, s1.roll);
    printf("name = %s\t age = %d\t std = %d monthly fees = %d\t annual fees = %d\t roll no = %d\n", s2.name, s2.age, s2.std, s2.monthly_fees, s2.annual_fees, s2.roll);
    
    
    return 0;
}