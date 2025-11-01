#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bitCount(int num){
    int count = log(num)/log(2);
    return count+1;
}

void bit(int num, int *arr, int bitcount){
    for(int i=1; i<=bitcount; i++){
        int bit = (num>>(bitcount-i)) & 1;
        arr[i-1] = bit;
    }
}

void binAdd(int *arr1, int *arr2, int bitcount){
    int sum, carry;
    sum = carry = 0;
    for(int i=(bitcount-1); i>=0 ;i--){
        sum = (arr1[i]^arr2[i]) ^ carry;
        carry = (arr1[i] & arr2[i]) | ((arr1[i]^arr2[i]) & carry);
        arr1[i] = sum;
    }
}

void twos(int *arr, int bitcount){
    for(int i=0; i<bitcount; i++){
        if(arr[i] == 0){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }

    int arr2[bitcount];
    for(int i=0; i<bitcount; i++){
        if(i==0){
            arr2[i] = 1;
        }
        else{
            arr2[i] = 0;
        }
    }

    binAdd(arr, arr2, bitcount);
}

void lsl(int *a, int *q, int bitcount){
    int qMSB = q[0];

    for(int i=0; i<bitcount; i++){
        if(i!=bitcount-1){
            q[i] = q[i+1];
        }
    }

    for(int i=0; i<=bitcount; i++){
        if(i != bitcount){
            a[i] = a[i+1];
        }
        else{
            a[i] = qMSB;
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
    int divisor = 3; //m
    int dividend = 12; //q

    divisor = abs(divisor);
    dividend = abs(dividend);

    int bigInt = (divisor>dividend)? divisor : dividend;
    int bitNum = bitCount(bigInt);


    int a[bitNum+1];
    for(int i=0; i<=bitNum; i++){
        a[i]=0;
    }

    int q[bitNum];
    bit(dividend, q, bitNum);

    int m[bitNum+1];
    bit(divisor, m, bitNum+1);

    int m2s[bitNum+1];
    bit(-(divisor), m2s, bitNum+1);

    for(int i=0; i<bitNum; i++){
        lsl(a, q, bitNum);

        if(a[0] == 0){
            binAdd(a, m2s, bitNum+1);
        }
        else{
            binAdd(a, m, bitNum+1);
        }

        if(a[0] == 0){
            q[bitNum -1] = 1;
        }
        else{
            q[bitNum -1] = 0;
        }
    }

    if(a[0] == 1){
        binAdd(a, m, bitNum+1);
    }

    printarr(a, bitNum+1);
    printarr(q, bitNum);

    return 0;
}