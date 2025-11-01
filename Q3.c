  #include <stdio.h>
   union Data {
   int i;
   float f;
   char ch;
   };
   
   
   int main()
   {
   union Data d;
   d.i =10;
   
   printf("i=%d\n",d.i);
   d.f =3.14;
   
   printf("i=%d\n",d.f);
d.ch ='A';
   
   printf("i=%d\n",d.ch);
   

   
   return 0;



}
