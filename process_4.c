#include <stdio.h>
#include <time.h>

int factorial(int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}
int main(){
    int n=30;
    printf("P4 : Factorial\n\n");
    printf("%d",factorial(n));
    printf("\n");
    return 0;    
}
