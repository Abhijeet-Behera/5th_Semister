#include <stdio.h>

int main(){
    int Num;
    printf("Enter the number: ");
    scanf("%d",&Num);
    if(Num%2==0)
        printf("The Number is Even:");
    else
        printf("The Number is Odd:");
    return 0;
}