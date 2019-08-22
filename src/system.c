#include "system.h"

#include <libopencm3/cm3/nvic.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/stm32/adc.h>
#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/i2c.h>
#include <stdio.h>
#include "delay.h"
#include "uart.h"

volatile uint32_t millis;

static void clock_setup(void) {
    rcc_clock_setup_in_hse_8mhz_out_72mhz();
    delayInit();
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_AFIO);

    rcc_periph_clock_enable(RCC_DMA1);
    rcc_periph_clock_enable(RCC_USART2);
}

static void systick_setup(void) {
    nvic_set_priority(NVIC_SYSTICK_IRQ, 0x10);
    systick_set_reload(89999);
}

static void gpio_setup(void) {
    // Uart debug
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ,
                  GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART2_TX);
}

static void nvic_start(void) {
    systick_interrupt_enable();
}

void system_setup() {
    clock_setup();
    systick_setup();
    uart_setup();
    gpio_setup();
}

void system_start() {
    nvic_start();
    systick_counter_enable();
}