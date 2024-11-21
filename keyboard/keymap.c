#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include "features/achordion.h"
// #include "print.h"

//Key Definitions
// thumbs
#define LT_ESC LT(3,KC_ESC)
#define LT_SPC LT(2,KC_SPC)
#define LT_BSPC LT(1,KC_BSPC)
#define LT_ENT LT(4,KC_ENT)

// home rows
#define MOD_C LALT_T(KC_C)
#define MOD_I LGUI_T(KC_I)
#define MOD_E LSFT_T(KC_E)
#define MOD_A LCTL_T(KC_A)

#define MOD_H RCTL_T(KC_H)
#define MOD_T RSFT_T(KC_T)
#define MOD_S RGUI_T(KC_S)
#define MOD_N RALT_T(KC_N)

#define MOD_0 LALT_T(KC_0)
#define MOD_4 LGUI_T(KC_4)
#define MOD_5 LSFT_T(KC_5)
#define MOD_6 LCTL_T(KC_6)

#define MOD_DOT RCTL_T(KC_DOT)
                                

// Combos
const uint16_t PROGMEM combo_Q[] = {MOD_E, MOD_I, COMBO_END};
const uint16_t PROGMEM combo_Z[] = {MOD_T, MOD_S, COMBO_END};
const uint16_t PROGMEM combo_MEDIA[] = {LT_SPC, LT_BSPC, COMBO_END};
const uint16_t PROGMEM combo_FUNCTION[] = {LT_ESC, LT_ENT, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_Q, MT(MOD_LSFT | MOD_LGUI, KC_Q)),
    COMBO(combo_Z, MT(MOD_LSFT | MOD_LGUI, KC_Z)),
    COMBO(combo_MEDIA, LT(5,KC_CAPS)),
    COMBO(combo_FUNCTION, MO(6)),
};

// Overrides, most of these just remove shift functionality
const key_override_t override_CSTAB = ko_make_basic(MOD_MASK_CS, LT_BSPC, LCTL(LSFT(KC_TAB)));
const key_override_t override_SGTAB = ko_make_basic(MOD_MASK_SG, LT_BSPC, LGUI(LSFT(KC_TAB)));
const key_override_t override_SATAB = ko_make_basic(MOD_MASK_SA, LT_BSPC, LALT(LSFT(KC_TAB)));

const key_override_t override_TAB = ko_make_basic(MOD_MASK_SHIFT, LT_SPC, LT(2,KC_TAB));
const key_override_t override_DEL = ko_make_basic(MOD_MASK_SHIFT, LT_BSPC, LT(1,KC_DEL));

const key_override_t override_0 = ko_make_basic(MOD_MASK_SHIFT, MOD_0, MOD_0);
const key_override_t override_1 = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);
const key_override_t override_2 = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);
const key_override_t override_3 = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);
const key_override_t override_4 = ko_make_basic(MOD_MASK_SHIFT, MOD_4, MOD_4);
const key_override_t override_5 = ko_make_basic(MOD_MASK_SHIFT, MOD_5, MOD_5);
const key_override_t override_6 = ko_make_basic(MOD_MASK_SHIFT, MOD_6, MOD_6);
const key_override_t override_7 = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);
const key_override_t override_8 = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);
const key_override_t override_9 = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);

const key_override_t override_MINS = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_MINS);
const key_override_t override_EQL = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);
const key_override_t override_LBRC = ko_make_basic(MOD_MASK_SHIFT, KC_LBRC, KC_LBRC);
const key_override_t override_RBRC = ko_make_basic(MOD_MASK_SHIFT, KC_RBRC, KC_RBRC);
const key_override_t override_BSLS = ko_make_basic(MOD_MASK_SHIFT, KC_BSLS, KC_BSLS);
const key_override_t override_SCLN = ko_make_basic(MOD_MASK_SHIFT, KC_SCLN, KC_SCLN);
const key_override_t override_QUOT = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_QUOT);
const key_override_t override_GRV = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);
const key_override_t override_COMM = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_COMM);
const key_override_t override_DOT = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_DOT);
const key_override_t override_MOD_DOT = ko_make_basic(MOD_MASK_SHIFT, MOD_DOT, MOD_DOT);
const key_override_t override_SLSH = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH);

const key_override_t *key_overrides[] = {
    &override_CSTAB, &override_SGTAB, &override_SATAB,
    &override_TAB, &override_DEL, 
    &override_0, &override_1, &override_2, &override_3, &override_4, &override_5, &override_6, &override_7, &override_8, &override_9, 
    &override_MINS,
    &override_EQL,
    &override_LBRC,
    &override_RBRC,
    &override_BSLS,
    &override_SCLN,
    &override_QUOT,
    &override_GRV,
    &override_COMM,
    &override_DOT,
    &override_MOD_DOT,
    &override_SLSH,
};

// Detect OS
bool os_detected = false;
bool on_macos = false;

bool process_detected_host_os_user(os_variant_t detected_os) {
    on_macos = detected_os == OS_MACOS;
    os_detected = true;
    return true;
}

// Macros
enum custom_keycodes {
    MKC_PASTE = SAFE_RANGE,
    MKC_COPY,
    MKC_CUT,
    MKC_UNDO,
    MKC_REDO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // xprintf("%d %d\n", record->event.key.row, record->event.key.col);

    // capture achordion
    if (!process_achordion(keycode, record)) { return false; }

    // editing macros
    switch (keycode) {
    case MKC_PASTE:
        if (os_detected) {
            if (record->event.pressed) {
                if (on_macos) {
                    register_code16(LGUI(KC_V));
                } else {
                    register_code16(LCTL(KC_V));
                }
            } else {
                if (on_macos) {
                    unregister_code16(LGUI(KC_V));
                } else {
                    unregister_code16(LCTL(KC_V));
                }
            }
        }
        return false;
    case MKC_COPY:
        if (os_detected) {
            if (record->event.pressed) {
                if (on_macos) {
                    register_code16(LGUI(KC_C));
                } else {
                    register_code16(LCTL(KC_C));
                }
            } else {
                if (on_macos) {
                    unregister_code16(LGUI(KC_C));
                } else {
                    unregister_code16(LCTL(KC_C));
                }
            }
        }
        return false;
    case MKC_CUT:
        if (os_detected) {
            if (record->event.pressed) {
                if (on_macos) {
                    register_code16(LGUI(KC_X));
                } else {
                    register_code16(LCTL(KC_X));
                }
            } else {
                if (on_macos) {
                    unregister_code16(LGUI(KC_X));
                } else {
                    unregister_code16(LCTL(KC_X));
                }
            }
        }
        return false;
    case MKC_UNDO:
        if (os_detected) {
            if (record->event.pressed) {
                if (on_macos) {
                    register_code16(LGUI(KC_Z));
                } else {
                    register_code16(LCTL(KC_Z));
                }
            } else {
                if (on_macos) {
                    unregister_code16(LGUI(KC_Z));
                } else {
                    unregister_code16(LCTL(KC_Z));
                }
            }
        }
        return false;
    case MKC_REDO:
        if (os_detected) {
            if (record->event.pressed) {
                if (on_macos) {
                    register_code16(LGUI(LSFT(KC_Z)));
                } else {
                    register_code16(LCTL(KC_Y));
                }
            } else {
                if (on_macos) {
                    unregister_code16(LGUI(LSFT(KC_Z)));
                } else {
                    unregister_code16(LCTL(KC_Y));
                }
            }
        }
        return false;
    }
    return true;
};

// Achordion
void matrix_scan_user(void) {
    achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 400;
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // only check alpha combos
  switch (tap_hold_keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        tap_hold_keycode &= 0xff;
  }
  switch (other_keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        other_keycode &= 0xff;
  }
  if (tap_hold_keycode > KC_Z || other_keycode > KC_Z) { return true; }

  return achordion_opposite_hands(tap_hold_record, other_record);
}

// Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha
    [0] = LAYOUT_split_3x5_3(
        KC_B,            KC_Y,            KC_O,            KC_U,            KC_NO,KC_NO,    KC_L,            KC_D,            KC_W,            KC_V,
        MOD_C,            MOD_I,            MOD_E,            MOD_A,            KC_NO,KC_NO,    MOD_H,           MOD_T,           MOD_S,           MOD_N,
        KC_G,            KC_X,            KC_J,            KC_K,            KC_NO,KC_NO,    KC_R,            KC_M,         KC_F,          KC_P,
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),

    // Number
    [1] = LAYOUT_split_3x5_3(
        KC_NO,            KC_7,           KC_8,            KC_9,            KC_NO,KC_NO,    LSFT(KC_SCLN),   KC_SCLN,         KC_QUOT,          KC_GRV,
        MOD_0,            MOD_4,            MOD_5,            MOD_6,            KC_NO,KC_NO,    MOD_DOT,         KC_COMM,         LSFT(KC_QUOT),    LSFT(KC_MINS),
        KC_BSPC,            KC_1,           KC_2,            KC_3,            KC_NO,KC_NO,    KC_EQL,          LSFT(KC_EQL),    KC_MINS,          LSFT(KC_GRV),
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),

    // Symbol
    [2] = LAYOUT_split_3x5_3(
        KC_NO,            KC_SLSH,        LSFT(KC_LBRC),   LSFT(KC_RBRC),   KC_NO,KC_NO,    LSFT(KC_7),      LSFT(KC_BSLS),   LSFT(KC_4),       KC_NO,
        LSFT(KC_COMM),    LSFT(KC_DOT),   LSFT(KC_9),      LSFT(KC_0),      KC_NO,KC_NO,    LSFT(KC_1),      LSFT(KC_SLSH),       LSFT(KC_3),   LSFT(KC_2),
        KC_SPC,            KC_BSLS,        KC_LBRC,         KC_RBRC,         KC_NO,KC_NO,    LSFT(KC_8),      LSFT(KC_6),      LSFT(KC_5),       KC_NO,
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),

    // Mouse
    [3] = LAYOUT_split_3x5_3(
        KC_NO,            MKC_CUT,        MKC_COPY,        MKC_PASTE,       KC_NO,KC_NO,    MKC_PASTE,       MKC_COPY,        MKC_CUT,       KC_NO,
        KC_NO,         MS_BTN3,         MS_BTN2,         MS_BTN1,         KC_NO,KC_NO,    MS_BTN1,         MS_BTN2,         MS_BTN3,       KC_NO,
        MS_LEFT,          MS_DOWN,        MS_UP,           MS_RGHT,         KC_NO,KC_NO,    MS_LEFT,         MS_DOWN,         MS_UP,         MS_RGHT,
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),

    // Editing
    [4] = LAYOUT_split_3x5_3(
        KC_NO,            MKC_CUT,            MKC_COPY,            MKC_PASTE,            KC_NO,KC_NO,    MKC_PASTE,            MKC_COPY,            MKC_CUT,            KC_NO,
        KC_LALT,          KC_LGUI,          KC_LSFT,          KC_LCTL,          KC_NO,KC_NO,    KC_LEFT,              KC_DOWN,          KC_UP,          KC_RIGHT,
        KC_NO,            KC_NO,            MKC_REDO,            MKC_UNDO,            KC_NO,KC_NO,    MKC_UNDO,            MKC_REDO,         KC_NO,          KC_NO,
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),

    // Media
    [5] = LAYOUT_split_3x5_3(
        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_BRID,           KC_BRIU,          KC_NO,        KC_NO,KC_NO,    KC_MUTE,     KC_VOLD,          KC_VOLU,          KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_NO,            KC_NO,            KC_NO,
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),

    // Function
    [6] = LAYOUT_split_3x5_3(
        KC_NO,            KC_F9,            KC_F10,           KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_F11,           KC_F12,           KC_NO,
        KC_F1,            KC_F2,            KC_F3,            KC_F4,        KC_NO,KC_NO,    KC_F5,       KC_F6,            KC_F7,            KC_F8,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_NO,            KC_NO,            KC_NO,
                                          LT_ESC,          LT_SPC,          KC_NO,KC_NO,    LT_BSPC,         LT_ENT 
    ),


    // Gaming 1
    [7] = LAYOUT_split_3x5_3(
        KC_B,            KC_Y,            KC_O,            KC_U,            KC_NO,KC_NO,    KC_L,            KC_D,            KC_W,            KC_V,
        LALT_T(KC_C),    LGUI_T(KC_I),    LSFT_T(KC_E),    LCTL_T(KC_A),    KC_NO,KC_NO,    RCTL_T(KC_H),    RSFT_T(KC_T),    RGUI_T(KC_S),    RALT_T(KC_N),
        KC_G,            KC_X,            KC_J,            KC_K,            KC_NO,KC_NO,    KC_R,            KC_M,         KC_F,          KC_P,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Gaming 2
    [8] = LAYOUT_split_3x5_3(
        KC_B,            KC_Y,            KC_O,            KC_U,            KC_NO,KC_NO,    KC_L,            KC_D,            KC_W,            KC_V,
        LALT_T(KC_C),    LGUI_T(KC_I),    LSFT_T(KC_E),    LCTL_T(KC_A),    KC_NO,KC_NO,    RCTL_T(KC_H),    RSFT_T(KC_T),    RGUI_T(KC_S),    RALT_T(KC_N),
        KC_G,            KC_X,            KC_J,            KC_K,            KC_NO,KC_NO,    KC_R,            KC_M,         KC_F,          KC_P,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Roguelike
    [9] = LAYOUT_split_3x5_3(
        KC_B,            KC_Y,            KC_O,            KC_U,            KC_NO,KC_NO,    KC_L,            KC_D,            KC_W,            KC_V,
        LALT_T(KC_C),    LGUI_T(KC_I),    LSFT_T(KC_E),    LCTL_T(KC_A),    KC_NO,KC_NO,    RCTL_T(KC_H),    RSFT_T(KC_T),    RGUI_T(KC_S),    RALT_T(KC_N),
        KC_G,            KC_X,            KC_J,            KC_K,            KC_NO,KC_NO,    KC_R,            KC_M,         KC_F,          KC_P,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)