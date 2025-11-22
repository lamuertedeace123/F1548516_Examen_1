#include <stdio.h>
#include <stdint.h>
#include "regs.h"

/* Prototipos */
void buttons_init(void);
void buttons_check_and_update(uint32_t *sample_time);
void led_init(void);
void led_off(void);
void led_set_red(void);
void led_set_green(void);
void led_set_blue(void);
void adc_init_regs(void);
uint32_t adc_read_one_shot_channel6(void);

/* Busy delay (ms) */
static void busy_delay_ms(volatile uint32_t ms) {
    volatile uint32_t i, j;
    for (i = 0; i < ms; ++i) for (j = 0; j < 4000; ++j) { __asm__ volatile("nop"); }
}

int main(void) {
    uint32_t sample_time = 2; /* segundos, valor inicial */
    uint32_t samples[10];

    /* Init peripherals */
    buttons_init();
    led_init();
    adc_init_regs();

    printf("Sistema ADC - inicio\n");

    while (1) {
        /* Periodo de ajuste: permitir al usuario cambiar sample_time antes de iniciar un ciclo */
        printf("Tiempo de muestreo actual: %u s. Ajuste con botones...\n", sample_time);
        /* Durante 2 segundos leemos botones para permitir cambios */
        uint32_t allow_ms = 2000;
        uint32_t t = 0;
        while (t < allow_ms) {
            buttons_check_and_update(&sample_time);
            busy_delay_ms(50);
            t += 50;
        }

        /* Indicar color segun rango */
        if (sample_time >=2 && sample_time <=10) {
            led_set_red();
        } else if (sample_time >=12 && sample_time <=16) {
            led_set_blue();
        } else { /* 18 o 20 */
            led_set_green();
        }

        /* Mantener LED encendido durante las 10 muestras */
        uint32_t sum = 0;
        for (int i = 0; i < 10; ++i) {
            samples[i] = adc_read_one_shot_channel6();
            sum += samples[i];
            /* pequeña pausa entre lecturas */
            busy_delay_ms(10);
        }

        /* Apagar LED */
        led_off();

        uint32_t avg = sum / 10U;
        printf("Promedio ADC (10 muestras) = %u  |  Tiempo de muestreo = %u s\n", avg, sample_time);

        /* Esperar sample_time segundos antes de siguiente ciclo. Durante ese tiempo el usuario puede ajustar */
        for (uint32_t sec = 0; sec < sample_time; ++sec) {
            /* chequear botones cada 200 ms */
            for (int i = 0; i < 5; ++i) {
                buttons_check_and_update(&sample_time);
                busy_delay_ms(200);
            }
        }
    }

    return 0;
}