
#ifndef P4_REGS_H
#define P4_REGS_H

#include <stdint.h>

/* BASES */
#define DR_REG_SENS_BASE  0x3FF48800UL
#define DR_REG_GPIO_BASE  0x3FF44000UL

/* SENS registers */
#define SENS_SAR_READ_CTRL_REG    (*(volatile uint32_t *)(DR_REG_SENS_BASE + 0x0000))
#define SENS_SAR_START_FORCE_REG  (*(volatile uint32_t *)(DR_REG_SENS_BASE + 0x002C))
#define SENS_SAR_ATTEN1_REG       (*(volatile uint32_t *)(DR_REG_SENS_BASE + 0x0034))
#define SENS_SAR_MEAS_START1_REG  (*(volatile uint32_t *)(DR_REG_SENS_BASE + 0x0054))

/* GPIO registers */
#define GPIO_OUT_REG        (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x0004))
#define GPIO_OUT_W1TS_REG   (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x0008))
#define GPIO_OUT_W1TC_REG   (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x000C))
#define GPIO_ENABLE_REG     (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x0020))
#define GPIO_ENABLE_W1TS_REG (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x0020))
#define GPIO_ENABLE_W1TC_REG (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x0024))
#define GPIO_IN_REG         (*(volatile uint32_t *)(DR_REG_GPIO_BASE + 0x003C))

/* Pines */
#define SW_INC_GPIO    5
#define SW_DEC_GPIO    4
#define POT_GPIO       34
#define LED_B_GPIO     25
#define LED_G_GPIO     26
#define LED_R_GPIO     27

/* Bit helpers */
#define BIT(n) (1U << (n))

/* GPIO helpers */
#define gpio_set(pin)   (GPIO_OUT_W1TS_REG = BIT(pin))
#define gpio_clear(pin) (GPIO_OUT_W1TC_REG = BIT(pin))
#define gpio_dir_output(pin) (GPIO_ENABLE_W1TS_REG = BIT(pin))
#define gpio_dir_input(pin)  (GPIO_ENABLE_W1TC_REG = BIT(pin))
#define gpio_read(pin)  ((GPIO_IN_REG >> (pin)) & 0x1U)