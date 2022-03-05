#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 15;
const uint BUTTON_PIN = 14;

int main()
{
    // Initialise I/O
    stdio_init_all();

    // Initialise GPIO PIN 15 for LED
    // Initialise GPIO PIN 14 for BUTTON
    gpio_init(LED_PIN);
    gpio_init(BUTTON_PIN);

    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);

    uint userInput = 0;
    uint ledOnOff = 0;

    while(1)
    {
        // Get User Input
        printf("Command (1 = on or 0 = off):\n");
        userInput = gpio_get(BUTTON_PIN);

        if(userInput == 1 && ledOnOff == 0)
        {
            // Turn on LED
            gpio_put(LED_PIN,1);
            printf("LED switched on!\n");
            ledOnOff = 1;
            sleep_ms(1000);
        }
        else if(userInput == 1 && ledOnOff == 1)
        {
            // Turn off LED
            gpio_put(LED_PIN,0);
            printf("LED switched off!\n");
            ledOnOff = 0;
            sleep_ms(1000);
        }
        else
        {
            printf("Invalid Input!\n");
            sleep_ms(1000);
        }    

    }
}