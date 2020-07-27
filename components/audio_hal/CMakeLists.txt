set(COMPONENT_ADD_INCLUDEDIRS ./include)

# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES audio_sal audio_board mbedtls esp_peripherals esp_dispatcher)

set(COMPONENT_SRCS ./audio_hal.c)

register_component()
