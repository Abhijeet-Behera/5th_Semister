  #include <stdio.h>
   union Student {
   int id;
   char name[30];
   float marks;
   };
   
   
   int main()
   {
   union Student s1  = {101,"A",88.5};
   printf("ID: %d\n",s1.id);
   printf("Name: %s\n",s1.name);
   printf("Marks: %.2f\n",s1.marks);
   
   printf("Base address of s1 id: %p\n", (void*)&s1.id);
   printf("Base address of s1 name: %p\n", (void*)&s1.name);
printf("Base address of s1 mark: %p\n", (void*)&s1.marks);

   
   return 0;



}
