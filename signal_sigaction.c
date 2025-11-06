/**
 * File:  signal_sigaction.c
 * Modified by: Elias Mouthey
 * 
 * Brief summary of program:
 * - Demonstrates registering a handler for the SIGUSR1 signal using sigaction.
 * - Prints the process ID of the sender whenever SIGUSR1 is received.
 * - Waits in an infinite loop to receive signals.
 * - Example command to send SIGUSR1: kill -SIGUSR1 <pid>
 */

#define _POSIX_C_SOURCE 199309L //used for sigaction
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig, siginfo_t *info, void *context) 
{
    (void)context; // unused
    printf("Received SIGUSR1 from sender PID: %d\n", info->si_pid);
}

int main(void) 
{
    struct sigaction sa;

    // Clear the sigaction struct
    sa.sa_flags = SA_SIGINFO;       // Use sa_sigaction instead of sa_handler
    sa.sa_sigaction = handle_sigusr1;
    sigemptyset(&sa.sa_mask);       // No additional signals blocked

    // Register the handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Process PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signals...\n");

    // Infinite loop to wait for signals
    while (1) 
    {
        pause();  // Wait for signal
    }

    return 0;
}
