#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>


#define N 5

int main()
{

 sem_t *sem = mmap(NULL, sizeof(sem_t),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
 sem_init(sem,1,1);
 for(int p=0;p<N;p++)
 {
 	if(fork()==0)
 	{
 		for(int i=0;i<3;i++)
 		{
 			sem_wait(sem);
 			printf("Process:%d PID=%d is Critical Section %d\n",p,getpid(),i);
 			sleep(1);
 			sem_post(sem);
 			sleep(1);
 		}	 		
 	}
 return 0;
 }
 while (wait(NULL)>0);
 return 0;
 }
