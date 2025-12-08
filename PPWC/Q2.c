#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>

int main()
{

 int *counter = mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
 *counter =0;
 
 if(fork()==0)
 {
 	for(int i=0;i<10000;i++)
 	(*counter)++;
 	return 0;
 }
 else{
 	for(int i=0;i<10000;i++)
 	(*counter)++;
 }
 
wait(NULL);
printf("Final Counter = %d  (Expected=20000)\n", *counter);
return 0;
}
