#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int counter = 0;
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid == 0) {
        counter += 2;  
    } else {
        counter++;
    }
    printf("counter = %d,PPID=%d\n", counter,getpid());
    return 0;
}

