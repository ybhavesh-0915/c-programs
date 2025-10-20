#include <stdio.h>
#include <string.h>
//variable length array is not possible in structure but flexible array are possible in c but it should be last member of structure
struct employe{
    int ID;
    int age;
    int salary;
    char name[64];
};

void remove_new_line_character(char *str){
    int length = strlen(str);
    char new_str[length];
    strcpy(new_str, str);
    strcpy(str, "\0");

    int i=0;
    for(i=0; i<length-1; i++){
        str[i] = new_str[i];
    }

    str[i] = '\0';
}

int main(){
    struct employe e[5];

    int IDs[5]={1,2,3,4,5};
    int ages[5]={20,25,30,19,22};
    int salaries[5]={20000, 30000, 40000, 50000, 60000};
    
    for(int i=0; i<5; i++){
        char name[64];
        printf("Enter the name of employe having id %d:", IDs[i]);
        fgets(name, sizeof(name), stdin);
        remove_new_line_character(name);
        strcpy(e[i].name, name);
        e[i].age = ages[i];
        e[i].salary = salaries[i];
        e[i].ID = IDs[i];
    }

    for(int i=0; i<5; i++){
        printf("name = %s \t age = %d \t salary = %d \t id = %d\n", e[i].name, e[i].age, e[i].salary, e[i].ID);
    }

    return 0;
}