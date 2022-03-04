#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 15;

int main()
{
    // Initialise I/O
    stdio_init_all();

    // Initialise GPIO PIN 15 for LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    char userInput;

    while(1)
    {
        // Get User Input
        printf("Command (1 = on or 0 = off):\n");
        userInput = getchar();

        if(userInput == '1')
        {
            // Turn on LED
            gpio_put(LED_PIN,1);
            printf("LED switched on!\n");
        }
        else if(userInput == '0')
        {
            // Turn off LED
            gpio_put(LED_PIN,0);
            printf("LED switched off!\n");
        }
        else
        {
            printf("Invalid Input!\n");
        }    
    }
}