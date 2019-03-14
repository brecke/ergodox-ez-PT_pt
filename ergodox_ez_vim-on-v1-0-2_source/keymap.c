#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_BSLASH,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,LALT(LGUI(KC_LEFT)),KC_LCTRL,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_HOME,LT(1,KC_NO),KC_GRAVE,KC_LBRACKET,KC_QUOTE,KC_RBRACKET,LCTL(KC_LEFT),LCTL(KC_RIGHT),KC_PGUP,KC_LGUI,LALT(KC_NO),KC_PGDOWN,KC_MINUS,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,LALT(LGUI(KC_RIGHT)),KC_Y,KC_U,KC_I,KC_O,KC_P,KC_RALT,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_RCTRL,KC_END,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,LT(2,KC_NO),KC_EQUAL,KC_SLASH,KC_DELETE,KC_CAPSLOCK,KC_ENTER,KC_SPACE),

  [1] = LAYOUT_ergodox(KC_ESCAPE,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,KC_EXLM,KC_AT,KC_LCBR,KC_RCBR,KC_PIPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_DLR,KC_LPRN,KC_RPRN,KC_GRAVE,KC_TRANSPARENT,KC_PERC,KC_CIRC,KC_LBRACKET,KC_RBRACKET,KC_KP_SLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_MOD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_VAD,RGB_VAI,KC_TRANSPARENT,KC_TRANSPARENT,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_TRANSPARENT,KC_UP,KC_7,KC_8,KC_9,KC_KP_ASTERISK,KC_F12,KC_DOWN,KC_4,KC_5,KC_6,KC_KP_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_AMPR,KC_1,KC_2,KC_3,KC_SLASH,KC_TRANSPARENT,KC_COMMA,KC_DOT,KC_0,KC_EQUAL,LT(2,KC_NO),RGB_TOG,RGB_SLD,KC_TRANSPARENT,KC_TRANSPARENT,RGB_HUD,RGB_HUI),

  [2] = LAYOUT_ergodox(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_BTN1,KC_MS_BTN2,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_STOP,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PREV_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_AUDIO_MUTE),

};

bool suspended = false;
rgb_config_t rgb_matrix_config;

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {85,203,158}, {10,225,255}, {10,225,255}, {10,225,255}, {134,255,213}, {85,203,158}, {10,225,255}, {10,225,255}, {10,225,255}, {134,255,213}, {134,255,213}, {10,225,255}, {10,225,255}, {10,225,255}, {134,255,213}, {134,255,213}, {134,255,213}, {10,225,255}, {134,255,213}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {0,0,0}, {134,255,213}, {10,225,255}, {10,225,255}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {0,0,0}, {0,0,0} },

};

void set_leds_color( int layer) {
  rgb_matrix_mode_noeeprom(1);
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    uint8_t val = pgm_read_byte(&ledmap[layer][i][2]);
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = val == 0 ? 0 : rgb_matrix_config.val
    };
    RGB rgb = hsv_to_rgb( hsv );
    rgb_matrix_set_color( i, rgb.r, rgb.g, rgb.b );
  }
}

void rgb_matrix_indicators_user(void) {
  if(suspended == false) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
      case 0:
        rgb_matrix_config.raw = eeprom_read_dword(EECONFIG_RGB_MATRIX);
        rgb_matrix_mode_noeeprom(rgb_matrix_config.mode);
        if(rgb_matrix_config.mode != 1) {
          rgb_matrix_sethsv_noeeprom(rgb_matrix_config.hue, rgb_matrix_config.sat, rgb_matrix_config.val);
        }
        break;
      case 1:
        set_leds_color(1);
        break;
      case 2:
        set_leds_color(2);
        break;
    }
  }
}
const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
