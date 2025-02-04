#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


#define LED_PIN_RED 13
#define LED_PIN_GREEN 11


bool repeating_timre_callback(struct repeating_timer *t){

    if ((int) t->user_data > 2)
        t->user_data = 0;
    
    if ((int) t->user_data == 0){
        gpio_put(LED_PIN_RED, true);
        gpio_put(LED_PIN_GREEN, false);
    }
    if ((int) t->user_data == 1){
        gpio_put(LED_PIN_GREEN, true);
    }
    if ((int) t->user_data == 2){
        gpio_put(LED_PIN_RED, false);
    }

    t->user_data++;

    return true;
}

int main()
{
    stdio_init_all();

    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, true);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, true);

    struct repeating_timer timer;
    timer.user_data = 0;

    add_repeating_timer_ms(3000, repeating_timre_callback, timer.user_data, &timer);

    while (true) {
        sleep_ms(1000);
        printf("+1 sec\n");
    }
}
