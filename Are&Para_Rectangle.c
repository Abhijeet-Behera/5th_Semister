#include <stdio.h>
#define pie 3.14
int main(){
    double Radius,Area,length,breadth,peri;
    printf("Lenght&Breadth: ");
    scanf("%lf%lf",&length,&breadth);
    Area=length*breadth;
    peri=2*length*breadth;

    printf("Area: %f",Area);
    printf("Perimeter: %f",peri);
    return 0;
}