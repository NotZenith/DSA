#include<stdio.h>

int sum(int a){
    if(a == 0){
        return 0;
    }
    else{
        return a + sum(a-1);
    }
}

int main(){
    int n, result;
    printf("Enter the nth term: ");
    scanf("%d", &n);

    result = sum(n);

    printf("\nThe sum of natural number of %dth term is %d\n",n,result);
}
