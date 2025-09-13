#include <stdio.h>
#define pie 3.14
int main(){
    double Radius,Area;
    printf("Radius: ");
    scanf("%lf",&Radius);
    Area=pie*Radius*Radius;
    printf("Area: %f",Area);
    return 0;
}