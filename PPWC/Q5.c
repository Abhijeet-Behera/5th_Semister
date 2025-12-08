#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>


int main()
{
sem_t *sem = sem_open("/persist",O_CREAT,0666,5);

int val;
sem_getvalue(sem,&val);
printf("Semaphore value =%d\n",val);
 
sem_wait(sem); 
sem_close(sem);
}
