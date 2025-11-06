/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT, the handler prints a message and then quits
 * - ctrl + c interupts the program
 * - can kill process id ex kill -SIGINT 12345 if process id is 12345
 * 
 */

/**
 * Modified by: Elias Mouthey
 * 
 * Brief summary of modifications:
 * if exit is removed the signal can be received but never exits
 * shows that a signal is recieved continues printing sleeping
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() 
{
    printf("Received a signal\n");
    //exit(1);
}

int main() 
{

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) 
    {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}