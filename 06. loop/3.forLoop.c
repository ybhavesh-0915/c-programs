#include <stdio.h>
#include <unistd.h>

int main(){
    int i;

    for(i=0; i<10; i++){
        printf("%d\n", i);
        sleep(1);
    };
    printf("last value of %d\n", i);


    for(int j=0; j<10; j = j+1){
        printf("%d\n", i);
        // sleep(1);s
    };
    printf("last value of %d\n", i);
    return 0;
    return 0;
}