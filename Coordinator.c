#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char** argv) {
    for (int i = 2; i < 6; i++)
    {
        int status;
        int y = fork();
        if (y == 0) {
            execlp("./checker","./checker", argv[1], argv[i], NULL);
        }
        else {
            printf("Coordinator: forked process with ID %d \n", y);
            printf("Coordinator: waiting for process [%d]\n", y);
            wait(&status);
            printf("Coordinator: child process %d returned %d\n", y, WEXITSTATUS(status));
        }
    }
}