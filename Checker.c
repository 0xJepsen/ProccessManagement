#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> 
#include <string.h>

int checker(int divisor, int numerator){
    int PID = getpid();
    printf("Checker process [%d]: Starting. \n", PID);
    if ((numerator % divisor) == 0 ){
        printf("Checker process [%d]: %d *IS* divisable by %d. \n", PID, numerator, divisor);
        printf("Checker process [%d]: Returning 1.\n", PID);
        return 1;
    }
    else {
        printf("Checker process [%d]: %d *IS NOT* divisable by %d. \n",PID, numerator, divisor);
        printf("Checker process [%d]: Returning 0.\n",PID);
        return 0;
    }
}
int main (int argc, char** argv){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    return checker(a,b);
}