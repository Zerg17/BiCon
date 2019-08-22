#include <stdio.h>
#include "delay.h"
#include "system.h"
#include "uart.h"

char bufC[64];

int main(void) {
    system_setup();
    system_start();

    while (1) {
        uint8_t buf[6];
    }
}