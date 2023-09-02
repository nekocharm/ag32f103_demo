#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>
#include <stdbool.h>

#include "alta.h"

#ifndef CLOCK_PERIOD
#define CLOCK_PERIOD (1e9/BOARD_PLL_FREQUENCY)
#endif
#ifndef RTC_PERIOD
#define RTC_PERIOD (1e9f/BOARD_RTC_FREQUENCY)
#endif
#ifndef BAUD_RATE
#define BAUD_RATE 500000
#endif

#ifndef FPGA_ADDR
#define FPGA_ADDR 0x80027000
#endif

#define MMIO_BASE (0x60000000)

#define LED_GPIO GPIO0
#define LED_GPIO_MASK APB_MASK_GPIO0
#define LED_GPIO_BITS (1<<0) // LED

SYS_HSE_BypassTypeDef board_hse_source(void);
RTC_ClkSourceTypeDef  board_rtc_source(void);
uint32_t board_lse_freq(void);
uint32_t board_pll_clkin_freq(void);

void board_init(void);
void board_led_write(bool state);
int board_uart_read(uint8_t *buf, int len);
int board_uart_write(void const *buf, int len);
uint32_t board_millis(void);
static inline void HardFault_Handler(void) { asm("ebreak"); }

#endif
