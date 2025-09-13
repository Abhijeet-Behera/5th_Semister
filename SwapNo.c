#include <stdio.h>

int main(){
    int Num1,Num2,x;
    printf("Enter the number: ");
    scanf("%d%d",&Num1,&Num2);

    printf("Num1 is: %d\t",Num1);
    printf("Num2 is: %d\n ",Num2);

    x=Num1;
    Num1=Num2;
    Num2=x;

    printf("Num1 is: %d\t",Num1);
    printf("Num2 is: %d\n",Num2);


    
    return 0;
}