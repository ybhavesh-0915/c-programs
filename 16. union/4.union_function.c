#include <stdio.h>
#include <stdlib.h>

union decimalUnion{
    float num1;
    double num2;
};

union myunion{
    int num;
    char str;
    union decimalUnion i;
};

// union myunion create_union(char str, char opt){
//     union myunion u1;
//     if(opt == 'n'){
//         u1.num = (int)str;
//     }
//     else{
//         u1.str = str;
//     }

//     return u1;
// }

union myunion *create_union(union myunion u1, union decimalUnion *u2){
    union myunion *un1 = (union myunion*)malloc(sizeof(union myunion));
    *un1 = u1;
    un1->i = *u2;

    return un1;
}

void flushBuffer(){
    int c;
    while((c=getchar()) != '\n' && c != EOF){}
}

int main(){
    // char x;
    // char val;
    // union myunion u1;
    // printf("choose the option (n)um, (s)tring: ");
    // scanf("%c", &x);
    // flushBuffer();
    // printf("Enter the value: ");
    // scanf("%c", &val);
    // switch(x){
    //     case 'n':{
    //         u1 = create_union(val, x);
    //         printf("%d\n", u1.num);
    //         break;
    //     }
    //     case 's':{
    //         u1 = create_union(val, x);
    //         printf("%c\n", u1.str);
    //         break;
    //     }
    //     default:{
    //         printf("invalid inp\n");
    //     }
    // }

    union myunion u1;
    u1.num = 5;

    union decimalUnion u2;
    u2.num1 = 5.236;

    union myunion *u3 = create_union(u1, &u2);

    // printf("%d", u3->num);
    printf("%f", u3->i.num1);

    
    return 0;
}