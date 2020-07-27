set(COMPONENT_ADD_INCLUDEDIRS include)

# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES audio_sal)
set(COMPONENT_PRIV_REQUIRES esp_dispatcher esp-adf-libs audio_pipeline audio_sal )

set(COMPONENT_SRCS ./player_action.c)

register_component()
