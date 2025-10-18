/*
    Static Memory
        > Program ke data segment me store hoti hai.
        > Compiler isko allocate karta hai (program start hote hi).
        > Lifetime pure program ke dauran rehta hai.
        > Function ke khatam hone ke baad bhi value preserve rehti hai.
        > Program end hone par hi destroy hoti hai.
        > Control compiler ke haath me hota hai (manual free nahi hota).
        > Mainly use hoti hai global aur static variables ke liye.

    Heap Memory
        > Program ke heap segment me banti hai.
        > Programmer isko malloc(), calloc(), ya realloc() se allocate karta hai.
        > Lifetime tab tak rehta hai jab tak tum usse free() nahi karte.
        > Agar free() na karo toh memory leak ho sakta hai.
        > Control programmer ke haath me hota hai.
        > Dynamic data structures (jaise arrays, linked lists, trees) ke liye useful hoti hai.
        > Allocation run-time pe hota hai (jab program execute ho raha hota hai).

    Static memory = compiler-controlled permanent storage
    Heap memory = programmer-controlled dynamic storage
*/

#include <stdio.h>
#include <stdlib.h>

FILE *createFile(char *fname, char *mode){
    FILE *fptr = NULL;
    fptr = fopen(fname, mode);
    return fptr;
}

FILE *createStaticFile(char *fname, char *mode){
    static FILE *fsptr = NULL;
    fsptr = fopen(fname, mode);
    return fsptr;
}

int main(){
    FILE *myFiles = createFile("file1.txt", "w");
    FILE *myStaticFiles1 =createStaticFile("file2.txt", "w");
    FILE *myStaticFiles2 =createStaticFile("file3.txt", "w");

    fclose(myFiles);
    fclose(myStaticFiles1);
    fclose(myStaticFiles2);
    return 0;
}