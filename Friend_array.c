#include <stdio.h>
int main ()
{
int Friend [10];
printf("Enter the serial no.s: ");
int max,s=0;
for(int i=0;i<10;i++)
{
scanf("%d",&Friend[i]);
}
for(int i=0;i<10;i++)
{
printf("%d\n",Friend[i]);
s+=Friend[i];
if(Friend[i]>max);
max=Friend[i];
}
printf("Sum is: %d\t",s);
printf("Max Among the array: %d\t",max);

return 0;
}
