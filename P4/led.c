#include "regs.h"

void led_init(void) {
    gpio_dir_output(LED_R_GPIO);
    gpio_dir_output(LED_G_GPIO);
    gpio_dir_output(LED_B_GPIO);
    /* Apagar inicialmente */
    gpio_clear(LED_R_GPIO);
    gpio_clear(LED_G_GPIO);
    gpio_clear(LED_B_GPIO);
}

void led_off(void) {
    gpio_clear(LED_R_GPIO);
    gpio_clear(LED_G_GPIO);
    gpio_clear(LED_B_GPIO);
}

void led_set_red(void) {
    gpio_set(LED_R_GPIO);
    gpio_clear(LED_G_GPIO);
    gpio_clear(LED_B_GPIO);
}
void led_set_green(void) {
    gpio_set(LED_G_GPIO);
    gpio_clear(LED_R_GPIO);
    gpio_clear(LED_B_GPIO);
}
void led_set_blue(void) {
    gpio_set(LED_B_GPIO);
    gpio_clear(LED_R_GPIO);
    gpio_clear(LED_G_GPIO);
}