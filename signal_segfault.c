/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 * - Installed a signal handler for SIGSEGV
 * - The handler prints a message when a segmentation fault occurs
 * - Demonstrates that returning from the handler without fixing the cause
 *   will re-trigger the segmentation fault
 */


#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handle_segfault(int sig) {
    printf("Received SIGSEGV (signal %d) — segmentation fault detected!\n", sig);
    // Returning without exiting will cause the fault to happen again
}

int main (int argc, char* argv[]) {
    // Install signal handler for SIGSEGV
    signal(SIGSEGV, handle_segfault);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}