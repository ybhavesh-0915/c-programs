#include <stdio.h>

FILE *create_file_pointer(char*, char*);

int main(){
   FILE *myfile = create_file_pointer("text.txt", "w");

   if(myfile != NULL){
    fprintf(stdout, "file created sucessfully\n");
   }

   return 0;
}

FILE *create_file_pointer(char *filename, char*mode){
    FILE *fptr = NULL;
    fptr = fopen(filename, mode);
    return fptr;
}