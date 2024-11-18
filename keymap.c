#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Combos
const uint16_t PROGMEM combo_Q[] = {LSFT_T(KC_E), LGUI_T(KC_I), COMBO_END};
const uint16_t PROGMEM combo_Z[] = {RSFT_T(KC_T), RGUI_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_MEDIA[] = {LT(2,KC_SPC), LT(1,KC_BSPC), COMBO_END};
const uint16_t PROGMEM combo_FUNCTION[] = {LT(3,KC_ESC), LT(4,KC_ENT), COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_Q, KC_Q),
    COMBO(combo_Z, KC_Z),
    COMBO(combo_MEDIA, MO(5)),
    COMBO(combo_FUNCTION, MO(6)),
};

// Overrides, most of these just remove shift functionality
const key_override_t override_TAB = ko_make_basic(MOD_MASK_SHIFT, LT(1,KC_SPC), LT(1,KC_TAB));
const key_override_t override_DEL = ko_make_basic(MOD_MASK_SHIFT, LT(2,KC_BSPC), LT(2,KC_DEL));

const key_override_t override_0 = ko_make_basic(MOD_MASK_SHIFT, LALT_T(KC_0), LALT_T(KC_0));
const key_override_t override_1 = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);
const key_override_t override_2 = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);
const key_override_t override_3 = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);
const key_override_t override_4 = ko_make_basic(MOD_MASK_SHIFT, LGUI_T(KC_4), LGUI_T(KC_4));
const key_override_t override_5 = ko_make_basic(MOD_MASK_SHIFT, LSFT_T(KC_5), LSFT_T(KC_5));
const key_override_t override_6 = ko_make_basic(MOD_MASK_SHIFT, LCTL_T(KC_6), LCTL_T(KC_6));
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
const key_override_t override_RCTL_DOT = ko_make_basic(MOD_MASK_SHIFT, RCTL_T(KC_DOT), KC_DOT);
const key_override_t override_SLSH = ko_make_basic(MOD_MASK_SHIFT, KC_SLSH, KC_SLSH);

const key_override_t *key_overrides[] = {
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
    &override_RCTL_DOT,
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
    MKC_PASTE,
    MKC_COPY,
    MKC_CUT,
    MKC_UNDO,
    MKC_REDO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

// Layouts
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Alpha
    [0] = LAYOUT_split_3x5_3(
        KC_B,            KC_Y,            KC_O,            KC_U,            KC_NO,KC_NO,    KC_L,            KC_D,            KC_W,            KC_V,
        LALT_T(KC_C),    LGUI_T(KC_I),    LSFT_T(KC_E),    LCTL_T(KC_A),    KC_NO,KC_NO,    RCTL_T(KC_H),    RSFT_T(KC_T),    RGUI_T(KC_S),    RALT_T(KC_N),
        KC_G,            KC_X,            KC_J,            KC_K,            KC_NO,KC_NO,    KC_R,            KC_M,         KC_F,          KC_P,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Number
    [1] = LAYOUT_split_3x5_3(
        KC_NO,            KC_7,           KC_8,            KC_9,            KC_NO,KC_NO,    LSFT(KC_SCLN),   KC_SCLN,         KC_QUOT,          KC_GRV,
        LALT_T(KC_0),     LGUI_T(KC_4),   LSFT_T(KC_5),    LCTL_T(KC_6),    KC_NO,KC_NO,    RCTL_T(KC_DOT),  KC_COMM,         LSFT(KC_QUOT),    LSFT(KC_MINS),
        KC_NO,            KC_1,           KC_2,            KC_3,            KC_NO,KC_NO,    KC_EQL,          LSFT(KC_EQL),    KC_MINS,          LSFT(KC_GRV),
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Symbol
    [2] = LAYOUT_split_3x5_3(
        KC_NO,            KC_SLSH,        LSFT(KC_LBRC),   LSFT(KC_RBRC),   KC_NO,KC_NO,    LSFT(KC_7),      LSFT(KC_BSLS),   LSFT(KC_4),       KC_NO,
        LSFT(KC_COMM),    LSFT(KC_DOT),   LSFT(KC_9),      LSFT(KC_0),      KC_NO,KC_NO,    LSFT(KC_SLSH),   LSFT(KC_1),      LSFT(KC_2),       LSFT(KC_3),
        KC_NO,            KC_BSLS,        KC_LBRC,         KC_RBRC,         KC_NO,KC_NO,    LSFT(KC_8),      LSFT(KC_6),      LSFT(KC_5),       KC_NO,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Mouse
    [3] = LAYOUT_split_3x5_3(
        KC_NO,            MKC_CUT,        MKC_COPY,        MKC_PASTE,       KC_NO,KC_NO,    MKC_PASTE,       MKC_COPY,        MKC_CUT,       KC_NO,
        KC_NO,         MS_BTN3,         MS_BTN2,         MS_BTN1,         KC_NO,KC_NO,    MS_BTN1,         MS_BTN2,         MS_BTN3,       KC_NO,
        MS_LEFT,          MS_DOWN,        MS_UP,           MS_RGHT,         KC_NO,KC_NO,    MS_LEFT,         MS_DOWN,         MS_UP,         MS_RGHT,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Editing
    [4] = LAYOUT_split_3x5_3(
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,KC_NO,    MKC_PASTE,            MKC_COPY,            MKC_CUT,            KC_NO,
        KC_LALT,          KC_LGUI,          KC_LSFT,          KC_LCTL,          KC_NO,KC_NO,    KC_LEFT,              KC_DOWN,          KC_UP,          KC_RIGHT,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,KC_NO,    MKC_UNDO,            MKC_REDO,         KC_NO,          KC_NO,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Media
    [5] = LAYOUT_split_3x5_3(
        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_BRID,           KC_BRIU,          KC_NO,        KC_NO,KC_NO,    KC_MUTE,     KC_VOLD,          KC_VOLU,          KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_NO,            KC_NO,            KC_NO,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
    ),

    // Function
    [6] = LAYOUT_split_3x5_3(
        KC_NO,            KC_F9,            KC_F10,           KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_F11,           KC_F12,           KC_NO,
        KC_F1,            KC_F2,            KC_F3,            KC_F4,        KC_NO,KC_NO,    KC_F5,       KC_F6,            KC_F7,            KC_F8,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,KC_NO,    KC_NO,       KC_NO,            KC_NO,            KC_NO,
                                          LT(3,KC_ESC),    LT(2,KC_SPC),    KC_NO,KC_NO,    LT(1,KC_BSPC),   LT(4,KC_ENT)
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
