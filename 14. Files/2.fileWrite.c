#include <stdio.h>

FILE *createFile(char *filename, char *mode){
    FILE *fptr = NULL;
    fptr = fopen(filename, mode);
    return fptr;
}

int main(){
    FILE *myfile = createFile("todo.txt", "w");
    char mystr[100];
    fgets(mystr, sizeof(mystr), stdin);
    fprintf(myfile, "%s", mystr);
    fclose(myfile);

    FILE *myfile1 = createFile("todo.txt", "a");
    fgets(mystr, sizeof(mystr), stdin);
    fprintf(myfile1, "%s", mystr);
    fclose(myfile1);

    return 0;
}