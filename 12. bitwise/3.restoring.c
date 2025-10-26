#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bitCount(int num){
    int bitcount = log(num)/log(2);
    return bitcount+1;
}

void bits(int num, int *arr, int bitcount){
    for(int i=1; i<=bitcount; i++){
        int bit = (num>>(bitcount-i)) & 1;
        arr[i-1] = bit;
    }
}

void binAdd(int *arr1, int *arr2, int bitcount){
    int carry = 0;
    int sum = 0;
    for(int i=(bitcount-1); i>=0; i--){
        sum = (arr1[i]^arr2[i])^carry;
        carry = (arr1[i]&arr2[i]) | ((arr1[i]^arr2[i]) & carry);
        arr1[i] = sum;
    }
}

void lsl(int *a, int *q, int bitcount){
    int qMSB = q[0];
    int aLSF = a[bitcount-1];

    for(int i=0; i<bitcount; i++){
        if(i!=(bitcount-1)){
            a[i]=a[i+1];
            q[i]=q[i+1];
        }
        else{
            a[i]=qMSB;
        }
    }
}

void printarr(int *arr, int bitNum){
    for(int i=0; i<bitNum; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int divident = 12; //divident q
    int divisor = -3; //divisor m

    int bigInt = (abs(divident) > abs(divisor))? abs(divident) : abs(divisor);
    int bitnum = bitCount(bigInt) + 1;

    int a[bitnum];
    for(int i=0; i<bitnum; i++){
        a[i]=0;
    }

    int acopy[bitnum];
    for(int i=0; i<bitnum; i++){
        acopy[i] = a[i];
    }

    int q[bitnum];
    bits(divident, q, bitnum);

    int m[bitnum];
    bits(abs(divisor), m, bitnum);

    int m2s[bitnum];
    bits(-abs(divisor), m2s, bitnum);

    for(int i=0; i<bitnum; i++){
        lsl(a, q, bitnum);
        for(int i=0; i<bitnum; i++){
             acopy[i]=a[i];
        } 

        if(divisor>0){
            binAdd(a, m2s, bitnum);
        }else{
            binAdd(a, m2s, bitnum);
        }

        q[bitnum-1] = (a[0]==1)? 0:1;

        if(a[0]==1){
            for(int i=0; i<bitnum; i++){
                a[i]=acopy[i];
            }
        }else{
           for(int i=0; i<bitnum; i++){
                acopy[i]=a[i];
            } 
        }
    }

    printf("Quotient = ");
    printarr(q, bitnum);

    printf("Remainder = ");
    printarr(a, bitnum);
    
    return 0;
}               