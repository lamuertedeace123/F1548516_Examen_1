#include "regs.h"
#include <stdint.h>

/* Inicializa ADC (configs básicas por registros según enunciado) */
void adc_init_regs(void) {
    /* SENS_SAR_ATTEN1_REG: poner bits 12 y 13 a 1 */
    SENS_SAR_ATTEN1_REG |= (BIT(12) | BIT(13));

    /* SENS_SAR_READ_CTRL_REG: poner bit 27 a 1 (y 16 y 17 si corresponde) */
    SENS_SAR_READ_CTRL_REG |= BIT(27);
    SENS_SAR_READ_CTRL_REG |= (BIT(16) | BIT(17));

    /* SENS_SAR_START_FORCE_REG: colocar bits 0 y 1 en 1 */
    SENS_SAR_START_FORCE_REG |= (BIT(0) | BIT(1));
}

/* Realiza una conversión one-shot en canal 6 (ADC1_CH6 / GPIO34) y devuelve el valor 0..4095 aproximado */
uint32_t adc_read_one_shot_channel6(void) {
    /* Preparar SENS_SAR_MEAS_START1_REG: set bits 31,18,17 y habilitar canal 6 bit 25 */
    uint32_t reg = SENS_SAR_MEAS_START1_REG;

    /* Poner bits de start: 31, 18, 17 */
    reg |= BIT(31) | BIT(18) | BIT(17);
    /* Habilitar canal 6: bit 25 */
    reg |= BIT(25);
    SENS_SAR_MEAS_START1_REG = reg;

    /* Monitorizar bit mrp (bit 16) hasta que pase de 0 a 1 */
    uint32_t prev = (SENS_SAR_MEAS_START1_REG >> 16) & 0x1U;
    uint32_t cur;
    do {
        cur = (SENS_SAR_MEAS_START1_REG >> 16) & 0x1U;
    } while (cur == 0);

    /* Leer bits 0..15 --> resultado ADC */
    uint32_t val = SENS_SAR_MEAS_START1_REG & 0xFFFFU;
    return val;
}