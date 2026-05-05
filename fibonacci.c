#include<stdio.h>

long factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

int main(){
    int n;
    long result;

    printf("enter value of n:");
    scanf("%d",&n);

    result = factorial(n);
    printf("Factorial of %d term is %d\n",n,result);


}