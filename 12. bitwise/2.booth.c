#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bitsCount(int num){
    int count = (log(abs(num)) / log(2))+1;
    return count;
}

void bits(int num, int *arr, int bitscount){
    for(int i=1; i<=bitscount; i++){
        int bit = (num>>(bitscount-i)) & 1;
        arr[i-1]= bit;
    }
}

void binAdd(int *op1, int *op2, int bitscount){
    int sum, carry = 0;
    for (int i=(bitscount-1) ; i>=0; i--){
        sum = (op1[i]^op2[i])^carry;
        carry = (op1[i]&op2[i]) | ((op1[i]^op2[i])&carry);
        op1[i] = sum; 
    }
}

void asr(int *a, int *q, int *q1, int bitcount){
    int la = a[bitcount-1];
    int lq = q[bitcount-1];

    (*q1) = lq;

    for(int i=(bitcount-1); i>=0; i--){
        if(i!=0){
            q[i] = q[i-1];
            a[i]= a[i-1];

        }
        else{
            q[i]=la;
        }
    }
}

void printarr(int *arr, int bitNum){
    for(int i=0; i<bitNum; i++){
        printf("%d", arr[i]);
    }
}

int main(){
    int multiplier = -14;
    int multiplicand = -4;

    int bigNum = abs(multiplier) > abs(multiplicand)? multiplier:multiplicand;
    const int bitNum = bitsCount(bigNum)+1;

    int q[bitNum];
    int q1 = 0;
    int m[bitNum];
    int m2s[bitNum];
    int a[bitNum];
    for(int i=0; i<bitNum; i++){
        a[i]=0;
    }

    bits(multiplier, q, bitNum);
    bits(abs(multiplicand), m, bitNum);
    bits(-(abs(multiplicand)), m2s, bitNum);

    for(int i=0; i<bitNum; i++){
        if(q[bitNum-1] == 0 && q1 == 1){
            if(multiplicand>0){
                binAdd(a, m, bitNum);
            }
            else{
                binAdd(a, m2s, bitNum);
            }
        }

        if(q[bitNum-1]==1 && q1==0){
            if(multiplicand<0){
                binAdd(a, m, bitNum);
            }
            else{
                binAdd(a, m2s, bitNum);
            }
        }
        asr(a, q, &q1, bitNum);
    }

    printarr(a, bitNum);
    printarr(q, bitNum);
    return 0;
}