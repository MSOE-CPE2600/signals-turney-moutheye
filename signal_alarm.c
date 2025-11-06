/**
 * File: signal_alarm.c
 * Modified by:
 * 
 * Brief summary of program: Demonstrates use of alarm() and SIGALRM signal.
 * Description:
 *  - Sets an alarm for 5 seconds.
 *  - Installs a signal handler to catch SIGALRM.
 *  - When the signal is received, prints a message instead of exiting.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Handler for SIGALRM signal
 */
void handle_alarm(int sig) {
    printf("Received SIGALRM (signal %d) — alarm triggered!\n", sig);
}

int main(void) {
    
    signal(SIGALRM, handle_alarm);

    printf("Setting an alarm for 5 seconds...\n");
    alarm(5);  

    while (1) {
        printf("Waiting for alarm...\n");
        sleep(1);
    }

    return 0;
}
