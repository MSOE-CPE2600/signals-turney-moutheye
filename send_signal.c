/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */

#define _POSIX_C_SOURCE 199506L //used for sigaction
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t pid = (pid_t)atoi(argv[1]);  // convert argument to integer PID
    if (pid <= 0) 
    {
        fprintf(stderr, "Invalid PID: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Seed random number generator
    srand(time(NULL));
    int random_value = rand() % 1000;  // random number between 0–999

    union sigval value;
    value.sival_int = random_value;

    printf("Sending SIGUSR1 to PID %d with sival_int = %d\n", pid, random_value);

    if (sigqueue(pid, SIGUSR1, value) == -1) 
    {
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    return 0;
}
