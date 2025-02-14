#include <unistd.h> // For usleep
#include <stdint.h> // For precise integer types

/**
 * ft_timer - Delays execution for a given time in milliseconds.
 * @ms: Time in milliseconds to wait.
 *
 * This function pauses the program execution for the specified time.
 * It is useful for animations, frame control, or timed events.
 */
void	ft_timer(uint32_t ms)
{
	if (ms > 0)
		usleep(ms * 1000000); // Convert milliseconds to microseconds
}

#include <stdio.h>

int main(void)
{
    printf("Starting timer...\n");
    ft_timer(2); // Wait for 2 seconds
    printf("2 seconds later...\n");

    return (0);
}
