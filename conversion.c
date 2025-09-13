#include <stdio.h>
#define KMS_To_Miles 1.609
int main(){
    double mile,kms;
    printf("Miles: ");
    scanf("%lf",& mile);
    kms=mile*KMS_To_Miles;
    printf("Kilometers: %f",kms);
    return 0;
}
