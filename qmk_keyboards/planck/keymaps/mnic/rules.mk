# none of my keyboards need LTO and it screws up I2C on my LSVI:
EXTRAFLAGS:=$(filter-out -flto,$(EXTRAFLAGS))

RGBLIGHT_ENABLE = no
AUDIO_ENABLE = no
