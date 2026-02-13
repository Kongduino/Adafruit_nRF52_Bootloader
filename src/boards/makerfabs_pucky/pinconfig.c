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

void showColor(uint8_t r, uint8_t g, uint8_t b) {
  for (uint8_t ix = 0; ix < 8; ix++) {
    if (g & 0b10000000) one();
    else zero();
    g = g << 1;
  }
  for (uint8_t ix = 0; ix < 8; ix++) {
    if (r & 0b10000000) one();
    else zero();
    r = r << 1;
  }
  for (uint8_t ix = 0; ix < 8; ix++) {
    if (b & 0b10000000) one();
    else zero();
    b = b << 1;
  }
}

void lightUp() {
  NRF_P0->OUT = (1UL << 25);
  NRF_P0->OUT ^= (1UL << 25);
  showColor(0, 0xFF, 0); // Green
}

void lightDFU() {
  NRF_P0->OUT = (1UL << 25);
  NRF_P0->OUT ^= (1UL << 25);
  showColor(0xFF, 0xFF, 0); // yellow
}