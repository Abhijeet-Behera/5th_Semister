#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>

int main()
{
    int *counter = mmap(NULL, sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1, 0);
    *counter = 0;  
    pid_t pid = fork();

    if (pid == 0) {
        *counter += 2;
        return 0;
    } else {
        *counter += 1;
        wait(NULL);
        printf("counter = %d PPID=%d\n", *counter,getpid());
    }

    return 0;
}

