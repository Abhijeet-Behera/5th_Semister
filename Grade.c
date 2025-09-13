#include <stdio.h>

int main(){
    int N;
    printf("Enter the Marks of the student in percentage: ");
    scanf("%d",&N);
    if(N>95)
        printf("The Student Grade is O");
    else if(N<=95&&N>85)
        printf("The Student Grade is A");
    else if(N<=85&&N>75)
        printf("The Student Grade is B");
    else if(N<=75&&N>65)
        printf("The Student Grade is C");
    else if(N<=65&&N>55)
        printf("Please Sucide:)");
    return 0;
}