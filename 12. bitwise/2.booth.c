#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bits(int num, int *arr, int bitsCount){
    for(int i=1; i<=bitsCount; i++){
        int bit = (num>>(bitsCount-i)) & 1;
        arr[i-1]= bit;
    }
}

int bitsCount(int num){
    int count = (log(abs(num)) / log(2))+1;
    return count;
}

void binAdd(int *arr){

}


void printarr(int *arr, int bitNum){
    for(int i=0; i<bitNum; i++){
        printf("%d", arr[i]);
    }
} 
int main(){
    int multiplier = -7;
    int multiplicand = 3;

    int bigNum = abs(multiplier) > abs(multiplicand)? multiplier:multiplicand;
    const int bitNum = bitsCount(bigNum)+1;

    int q[bitNum];
    int m[bitNum];
    int a[bitNum];

    bits(multiplier, q, bitNum);
    bits(multiplicand, m, bitNum);

    printarr(q, bitNum);
    printf("\n");

    printarr(m, bitNum);
    printf("\n");

    return 0;
}

