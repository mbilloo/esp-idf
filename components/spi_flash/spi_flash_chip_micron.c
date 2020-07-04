#include "spi_flash_defs.h"
#include "spi_flash_chip_generic.h"
#include "spi_flash_chip_micron.h"
#include "esp_log.h"

/* Driver for Micron flash chip */
esp_err_t spi_flash_chip_micron_probe(esp_flash_t *chip, uint32_t flash_id)
{
    /* Check manufacturer ID matches that of Micron */
    if (flash_id >> 16 != MICRON_JEDEC_ID) {
        return ESP_ERR_NOT_FOUND;
    }

    return ESP_OK;
}

static const char chip_name[] = "micron";

esp_err_t spi_flash_chip_micron_detect_size(esp_flash_t *chip, uint32_t *size)
{
    /* Assuming that the Micron device has already been successfully probed */
    *size = 1 << (chip->chip_id & 0xFF);
    return ESP_OK;
}

const spi_flash_chip_t esp_flash_chip_micron = {
    .name = chip_name,
    .probe = spi_flash_chip_micron_probe,
    .reset = spi_flash_chip_generic_reset,
    .detect_size = spi_flash_chip_micron_detect_size,
    .erase_chip = spi_flash_chip_generic_erase_chip,
    .erase_sector = spi_flash_chip_generic_erase_sector,
    .erase_block = spi_flash_chip_generic_erase_block,
    .sector_size = 4 * 1024, /* Using smallest subsector size of 4 KB */
    .block_erase_size = 64 * 1024, /* Looks like block = sector */

    .get_chip_write_protect = spi_flash_chip_generic_get_write_protect,
    .set_chip_write_protect = spi_flash_chip_generic_set_write_protect,

    // Chip write protection regions do not appear to be standardised
    // at all, this is implemented in chip-specific drivers only.
    .num_protectable_regions = 0,
    .protectable_regions = NULL,
    .get_protected_regions = NULL,
    .set_protected_regions = NULL,

    .read = spi_flash_chip_generic_read,
    .write = spi_flash_chip_generic_write,
    .program_page = spi_flash_chip_generic_page_program,
    .page_size = 256,
    .write_encrypted = spi_flash_chip_generic_write_encrypted,

    .wait_idle = spi_flash_chip_generic_wait_idle,
    .set_io_mode = spi_flash_chip_generic_set_io_mode,
    .get_io_mode = spi_flash_chip_generic_get_io_mode,
};

