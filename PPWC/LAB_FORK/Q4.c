#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>  

#define SEM_NAME "/counter_sem"

int main()
{
    int *counter = mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
    *counter = 0;

    sem_t *sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0644, 1);
   
    pid_t pid = fork();

    if (pid == 0) {
        
        for (int i = 0; i < 100; i++) {
            sem_wait(sem);      //L
            (*counter)++;
            sem_post(sem);      // UL
        }
        return 0;
    } else {
        for (int i = 0; i < 100; i++) {
            sem_wait(sem);      // L
            (*counter)++;
            sem_post(sem);      // UL
        }
        wait(NULL);
        printf("Final counter = %d\n", *counter);
        sem_close(sem);
        sem_unlink(SEM_NAME);
    }

    return 0;
}

