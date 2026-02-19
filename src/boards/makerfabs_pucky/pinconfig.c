#include "boards.h"
#include "uf2/configkeys.h"

__attribute__((used, section(".bootloaderConfig")))
const uint32_t bootloaderConfig[] = {
  /* CF2 START */
  CFG_MAGIC0, CFG_MAGIC1, // magic
  5, 100, // used entries, total entries

  204, 0x100000, // FLASH_BYTES = 0x100000
  205, 0x40000, // RAM_BYTES = 0x40000
  208, (USB_DESC_VID << 16) | USB_DESC_UF2_PID,
  // BOOTLOADER_BOARD_ID = USB VID+PID, used for verification when updating bootloader via uf2
  209, 0xada52840, // UF2_FAMILY = 0xada52840
  210, 0x20, // PINS_PORT_SIZE = PA_32

  0, 0, 0, 0, 0, 0, 0, 0
  /* CF2 END */
};

void zero() {
  // One CPU Cycle Duration: 15.625 nanoseconds
  __disable_irq();
  // High 400 ns
  NRF_P0->OUT ^= (1UL << 25);
  asm volatile(
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 125 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 250 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 375 ns
    "MOV R0, R0; MOV R0, R0;");                                                                         // 406.25 ns
  NRF_P0->OUT ^= (1UL << 25);
  // Low 850 ns
  asm volatile(
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 125 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 250 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 375 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 500 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 625 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 750 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; ");                        // 843.75 ns
  __enable_irq();
}

void one() {
  // One CPU Cycle Duration: 15.625 nanoseconds
  __disable_irq();
  // High 800 ns
  NRF_P0->OUT ^= (1UL << 25);
  asm volatile(
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 125 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 250 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 375 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 500 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 625 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 750 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; ");                                                // 796.875 ns
  NRF_P0->OUT ^= (1UL << 25);
  // Low 450 ns
  asm volatile(
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 125 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 250 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; "  // 375 ns
    "MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; MOV R0, R0; ");                                    // 453.125 ns
  __enable_irq();
}

void lightRed() {
  PRINTF("[lightRed]:\tGRB: 0x00 0xFF 0x00");
  NRF_P0->OUTCLR = (1UL << WS1228B);
  // RGB: 0xFF 0x00 0x00
  // GRB: 0x00 0xFF 0x00
  for (uint8_t ix = 0; ix < 8; ix++)
    zero();
  for (uint8_t ix = 0; ix < 8; ix++)
    one();
  for (uint8_t ix = 0; ix < 8; ix++)
    zero();
}

void lightGreen() {
  PRINTF("[lightGreen]:\tGRB: 0xFF 0x00 0x00");
  NRF_P0->OUTCLR = (1UL << WS1228B);
  // RGB: 0x00 0xFF 0x00
  // GRB: 0xFF 0x00 0x00
  for (uint8_t ix = 0; ix < 8; ix++)
    one();
  for (uint8_t ix = 0; ix < 16; ix++)
    zero();
}

void lightYellow() {
  PRINTF("[lightYellow]:\tGRB: 0xFF 0xFF 0x00\r\n");
  // NRF_P0->OUTCLR = (1UL << WS1228B);
  // RGB: 0xFF 0xFF 0x00
  // GRB: 0xFF 0xFF 0x00
  for (uint8_t ix = 0; ix < 16; ix++)
    one();
  for (uint8_t ix = 0; ix < 8; ix++)
    zero();
}

void lightBlue() {
  PRINTF("[lightBlue]:\tGRB: 0x00 0x00 0xFF\r\n");
  // RGB: 0x00 0x00 0xFF
  // GRB: 0x00 0x00 0xFF
  for (uint8_t ix = 0; ix < 16; ix++)
    zero();
  for (uint8_t ix = 0; ix < 8; ix++)
    one();
}

void lightOff() {
  nrf_gpio_cfg_output(WS1228B);
  PRINTF("[lightOff]:\tClearing pin %d\r\n", WS1228B);
  NRF_P0->OUTCLR = (1UL << WS1228B);
  // RGB: 0x00 0x00 0x00
  // GRB: 0x00 0x00 0x00
  for (uint8_t ix = 0; ix < 24; ix++)
    zero();
}

