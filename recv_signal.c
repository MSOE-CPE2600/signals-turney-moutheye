/**
 * File: 
 * Modified by: Elias Mouthey
 * 
 * Brief summary of program:
 */

#define _POSIX_C_SOURCE 199309L //used for sigaction
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context) 
{
    (void)context; // unused
    if (info != NULL) 
    {
        printf("Received SIGUSR1 with sival_int: %d\n", info->si_value.sival_int);
    }
}

int main() {
    struct sigaction sa;

    // Clear the struct
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;       // Required to get siginfo_t
    sa.sa_sigaction = handle_sigusr1;

    // Register the handler
    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }
    printf("Receiver running with PID %d\n", getpid());
    fflush(stdout);  // flush PID output immediately

    // Wait indefinitely
    while (1) 
    {
        pause(); // sleeps until a signal is received
    }

    return 0;
}
