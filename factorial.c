#include<stdio.h>

int fact(int n){
    if(n==0 || n==1){
        return n;
    }

    else{
        return fact(n-1)+fact(n-2);
    }
}