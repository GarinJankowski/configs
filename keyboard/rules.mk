CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
OS_DETECTION_ENABLE = yes
MOUSEKEY_ENABLE = yes

CUSTOM_MATRIX = lite
WS2812_DRIVER = vendor
RGBLIGHT_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes
SRC += encoder.c
SRC += ghosting.c
SRC += matrix.c
SRC += features/achordion.c

CONSOLE_ENABLE = no
