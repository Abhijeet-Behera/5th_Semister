
#include <stdio.h>

int main(){
    float TotalMarks,Percentage,Math,Sci,Eng,Odia,ML,C;
    printf("Enter the marks of the 5 subjects/n maths/n Science/n English/n Odia/n ML/c C/n ");
    scanf("%f%f%f%f%f",&Math,&Sci,&Eng,&Odia,&ML,&C);
    TotalMarks=Math+Sci+Eng+Odia+ML+C;
    Percentage=(TotalMarks/500)*100;
    
    printf("Total Marks: %f\n",TotalMarks);
    printf("Total Percentage: %f",Percentage);
   
    return 0;
}