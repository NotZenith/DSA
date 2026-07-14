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
    int term;
    long result;

    printf("Enter the nth term: \n");
    scanf("%d", &term);

    for(int i = 0; i <= term; i++){
        result = factorial(i);
        printf("%d! = %ld\n", i, result);
    }
    return 0;
}