#include <stdio.h>

FILE *createFile(char*, char*);

int main(){
    FILE *file = createFile("todo.txt", "r");
    
    return 0;
}

FILE *createFile(char *filename, char *mode){
    FILE *fptr = fopen(filename, mode);
    return fptr;
}