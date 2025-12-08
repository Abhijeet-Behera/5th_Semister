#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>

int main() {sem_t *sem = mmap(NULL, sizeof(sem_t),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);

if (sem == MAP_FAILED) {
perror("mmap");
exit(1);
}
sem_init(sem, 1, 1);
pid_t pid = fork();
if (pid == 0) {  // Child process
 for (int i = 0; i < 5; i++) {
            sem_wait(sem);
            printf("Child in critical section: %d\n", i);
            sleep(1);
            sem_post(sem);
            sleep(1);
        }
    } 
  else { // Parent process
        for (int i = 0; i < 5; i++) {
            sem_wait(sem);
            printf("Parent in critical section: %d\n", i);
            sleep(1);
            sem_post(sem);
            sleep(1);
        }
    }

    return 0;
}

