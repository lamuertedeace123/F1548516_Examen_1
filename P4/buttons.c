#include "regs.h"
#include <stdint.h>
#include <stdio.h>

/* debounce simple: espera N iteraciones leyendo mismo estado */
static void busy_delay_ms(volatile uint32_t ms) {
    volatile uint32_t i, j;
    for (i = 0; i < ms; ++i) {
        for (j = 0; j < 4000; ++j) { __asm__ volatile("nop"); }
    }
}

void buttons_init(void) {
    /* Configurar pines como entrada */
    gpio_dir_input(SW_INC_GPIO);
    gpio_dir_input(SW_DEC_GPIO);
    /* No usamos registros de pull-ups específicos (depende de GPIO matrix/RTC),
       asumimos que hardware/boot setea pull-up interno; si no, habría que usar
       registros GPIO_STRAP o RTC_GPIO. */
}

/* Lee con debounce y devuelve 1 si presionado (activo bajo) */
static int read_button_debounced(int pin) {
    int v1 = gpio_read(pin);
    if (v1 != 0) return 0; /* nivel alto = no presionado (botón a GND) */
    busy_delay_ms(20);
    int v2 = gpio_read(pin);
    return (v2 == 0);
}

/* Actualiza sample_time (en segundos), asegurando par y límites */
void buttons_check_and_update(uint32_t *sample_time) {
    if (read_button_debounced(SW_INC_GPIO)) {
        if (*sample_time < 20) *sample_time += 2;
        /* esperar a que se suelte para evitar múltiples cambios rápidos */
        while (gpio_read(SW_INC_GPIO) == 0) { busy_delay_ms(10); }
    }
    if (read_button_debounced(SW_DEC_GPIO)) {
        if (*sample_time > 2) *sample_time -= 2;
        while (gpio_read(SW_DEC_GPIO) == 0) { busy_delay_ms(10); }
    }
}