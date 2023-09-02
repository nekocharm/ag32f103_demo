#include "blinky.h"


int main(void)
{
  board_init();
  /* in board_init();
  SYS_EnableAPBClock(LED_GPIO_MASK);
  GPIO_SetOutput(LED_GPIO, LED_GPIO_BITS);
  GPIO_SetHigh(LED_GPIO, LED_GPIO_BITS);
  */
  blinky();
}

void blinky()
{
  while (1) {
    UTIL_IdleUs(500e3);
    GPIO_Toggle(GPIO0, GPIO_BIT0);
  }
}