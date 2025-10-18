#include <stdio.h>
#include <unistd.h>

int main(){

    for(int i=0; i<10; i = i+2){
        printf("%d\n", i);
        continue;
        sleep(1); //never run
    };

    int i=0;
    while(i<10){
        sleep(1);
        i=i+1;
        if(i==5){
            continue;
        }
        printf("%d\n", i);
    };

    return 0;

}