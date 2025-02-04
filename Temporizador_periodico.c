#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


#define LED_PIN_RED 13
#define LED_PIN_GREEN 11
#define LED_PIN_BLUE 12


bool repeating_timre_callback(struct repeating_timer *t){

    printf("%d", t->user_data);
    return true;
}

int main()
{
    stdio_init_all();

    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);
    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, true);

    struct repeating_timer timer;
    timer.user_data = 0;

    add_repeating_timer_ms(1000, repeating_timre_callback, timer.user_data, &timer);

    while (true) {

    }
}
