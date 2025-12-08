#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>

int main()
{

 sem_t *sem_parent = mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
 sem_t *sem_child = mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
 	
 sem_init (sem_parent,1,1);
 sem_init (sem_child,1,0);
 
 if(fork()==0)
 {
 	for(int i=1;i<=10;i++)
 	{
 		sem_wait(sem_child);
 		printf("Child:%d\n",i);
 		sem_post(sem_parent);
 	}
 	return 0;
 }
 
 for(int i=0;i<=10;i++)
 {
 	sem_wait(sem_parent);
 	printf("Parent: %d\n",i);
 	sem_post(sem_child);
 }
 wait(NULL);
 }
