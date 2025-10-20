#include <stdio.h>

FILE *create_file_pointer(char *filename, char *mode){
    FILE *fptr = fopen(filename, mode);
    return fptr;
}
int main(){
    FILE *myfile = create_file_pointer("text.txt", "r");
    
    return 0;
}