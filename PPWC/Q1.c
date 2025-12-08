#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>

int main() {
    // Shared counter
    int *counter = mmap(NULL, sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1, 0);

    // Shared semaphore
    sem_t *sem = mmap(NULL, sizeof(sem_t),
                      PROT_READ | PROT_WRITE,
                      MAP_SHARED | MAP_ANONYMOUS,
                      -1, 0);

    if (counter == MAP_FAILED || sem == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    *counter = 0;

    // Initialize semaphore (1 = shared between processes)
    sem_init(sem, 1, 1);

    // Create 2 child processes
    for (int p = 0; p < 2; p++) {
        if (fork() == 0) {   // Child process
            for (int i = 0; i < 10; i++) {
                sem_wait(sem);
                (*counter)++;
                printf("Process %d incremented counter to %d\n", p + 1, *counter);
                sem_post(sem);
                usleep(100000); // 0.1 sec for nicer output
            }
            return 0; // Child exits
        }
    }

    // Parent waits for all children
    while (wait(NULL) > 0);

    // Final result
    printf("Final Counter = %d\n", *counter);

    return 0;
}

