#include <libopencm3/stm32/exti.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/dma.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/cm3/nvic.h>
#include <stdint.h>
#include "main.h"
#include "delay.h"
#include "system.h"
#include "tool.h"
#include "uart.h"

void sys_tick_handler() {
    millis++;
}