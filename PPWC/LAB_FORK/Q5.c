#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#define PARENT_SEM "/parent_sem"
#define CHILD_SEM  "/child_sem"

int main()
{
    int *counter = mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
    *counter = 0;
    sem_t *parent_sem = sem_open(PARENT_SEM, O_CREAT | O_EXCL, 0644, 1);
    sem_t *child_sem  = sem_open(CHILD_SEM,  O_CREAT | O_EXCL, 0644, 0);

    pid_t pid = fork();
    if (pid == 0) {
        for (int i = 1; i <= 5; i++) {
            sem_wait(child_sem);    
            (*counter)++;
            printf("Child  %d ppid=%d\n", i,getpid());
            sem_post(parent_sem);    
        }
        return 0;
    } else {
        
        for (int i = 1; i <= 5; i++) {
            sem_wait(parent_sem);    
            (*counter)++;
            printf("Parent %d ppid=%d\n", i,getpid());
            sem_post(child_sem);    
        }

        wait(NULL);

        sem_close(parent_sem);
        sem_close(child_sem);
        sem_unlink(PARENT_SEM);
        sem_unlink(CHILD_SEM);
    }

    return 0;
}

