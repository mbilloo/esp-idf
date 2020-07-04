#pragma once

#include "spi_flash_chip_driver.h"
#include "esp_flash.h"

#define MICRON_JEDEC_ID 0x20
/**
 * Micron SPI flash chip_drv. This is basically uses the generic driver but overloads the size detection
 * function
 */
extern const spi_flash_chip_t esp_flash_chip_micron;
