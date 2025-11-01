//WAP in c to reverse a string using pointer , create a function that takes strings base address and reverse 

#include <stdio.h>

void reverse(char *s) {
char *p = s;
char *q = s;
char t;
while (*q)
q++;
q--; 
while (p < q) {
t = *p;
*p = *q;
*q = t;
p++;
q--;
}}

int main() {
char str[100];
printf("Enter a string: ");
gets(str);
reverse(str);
printf("Reversed string: %s\n", str);
return 0;
}

