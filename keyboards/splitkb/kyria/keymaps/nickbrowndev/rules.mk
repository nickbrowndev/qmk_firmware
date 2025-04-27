
## Hardware features
OLED_ENABLE = yes
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = no     # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

## Software features

# Debounce algorithm https://docs.qmk.fm/#/feature_debounce_type
DEBOUNCE_TYPE = sym_eager_pk # Eager, per-key

# N-key rollover instead of 6-key rollover
NKRO_ENABLE = yes        # Enable N-Key Rollover

# Supported keycodes
MOUSEKEY_ENABLE = yes     # Mouse movement using keys
EXTRAKEY_ENABLE = yes     # Audio and system control
