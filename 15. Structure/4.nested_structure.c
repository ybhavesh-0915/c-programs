#include <stdio.h>

struct info{
    int std;
    int roll;
    int monthly_fees;
    int annual_fees;
}justin_info;

struct student{
    char name[64];
    int age;
    struct info i;
};

int main(){
    struct student bhavesh = {"Bhavesh Yadav", 19, {14, 10641, 2000, 24000}};

    justin_info.std = 14;
    justin_info.roll = 10639;
    justin_info.monthly_fees = 20000;
    justin_info.annual_fees = 2400000;

    struct student justin = {"Justion Thomas Roy", 19, justin_info};

    printf("name = %s\t age = %d\t std = %d monthly fees = %d\t annual fees = %d\t roll no = %d\n", bhavesh.name, bhavesh.age, bhavesh.i.std, bhavesh.i.monthly_fees, bhavesh.i.annual_fees, bhavesh.i.roll);

    printf("name = %s\t age = %d\t std = %d monthly fees = %d\t annual fees = %d\t roll no = %d\n", justin.name, justin.age, justin.i.std, justin.i.monthly_fees, justin.i.annual_fees, justin.i.roll);

}