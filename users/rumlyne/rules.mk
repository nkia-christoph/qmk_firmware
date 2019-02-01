#USER_NAME := rumlyne
SRC += rumlyne.c
#rumlyne := rumlyne.c

#ifneq ("$(wildcard $(USER_PATH)/secrets.h)","")
#  SRC += secrets.h
#endif

#ifeq ($(strip $(NO_SECRETS)), yes)
#    OPT_DEFS += -DNO_SECRETS
#endif

#ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
#  SRC += tap_dances.c
#endif

#ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
#  SRC += rgb_stuff.c
#  ifeq ($(strip $(INDICATOR_LIGHTS)), yes)
#      OPT_DEFS += -DINDICATOR_LIGHTS
#  endif
#  ifeq ($(strip $(RGBLIGHT_TWINKLE)), yes)
#    OPT_DEFS += -DRGBLIGHT_TWINKLE
#  endif
#  ifeq ($(strip $(RGBLIGHT_NOEEPROM)), yes)
#    OPT_DEFS += -DRGBLIGHT_NOEEPROM
#  endif
#endif

#ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
#  SRC += rgb_stuff.c
#endif

#ifeq ($(strip $(MACROS_ENABLED)), yes)
#    OPT_DEFS += -DMACROS_ENABLED
#endif

#ifdef CONSOLE_ENABLE
#  ifeq ($(strip $(KEYLOGGER_ENABLE)), yes)
#    OPT_DEFS += -DKEYLOGGER_ENABLE
#  endif
#endif

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
		TMK_COMMON_DEFS += -DCONSOLE_ENABLE
else
		TMK_COMMON_DEFS += -DNO_PRINT
		TMK_COMMON_DEFS += -DNO_DEBUG
endif

#EXTRAFLAGS += -flto LATER

BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
# AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = yes        # Unicode
# BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight. FUTURE TODO
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
TAP_DANCE_ENABLE = yes      # Enable Tap Dancing
