/*

qmk flash -kb crkbd/rev1 -km marcialr
 qmk compile -kb crkbd/rev1 -km marcialr


*/
#include "quantum.h"

#include QMK_KEYBOARD_H

void set_green(void) {
  rgblight_sethsv(85, 255, 255);
}
void set_red(void) {
  rgblight_sethsv(142, 255, 255);
}
void set_blue(void) {
  rgblight_sethsv(42, 255, 255);
}
void set_white(void) {
  rgblight_sethsv(0, 0, 255);
}

// Function to check if a specific layer is active
bool is_layer_active(uint8_t layer) {
  return layer_state_is(layer);
}

// Function to handle layer changes and backlight control
void process_layer_change(uint8_t layer) {
  static uint8_t previous_layer = 0; // Keep track of the previous layer

  if (layer != previous_layer) { // Check if the layer has actually changed
      previous_layer = layer; // Update the previous layer

      if (is_layer_active(_NAV)) {
          rgblight_enable(); // Or use rgblight_set_brightness() for finer control
          set_red();
      } else if (is_layer_active(_SYMBOLS)) {
          rgblight_enable(); // Or use rgblight_set_brightness() for finer control
          set_green();
      } else if (is_layer_active(_MATH)) {
          rgblight_enable(); // Or use rgblight_set_brightness() for finer control
          set_blue();
      } else if (is_layer_active(_COLOR)) {
          rgblight_enable(); // Or use rgblight_set_brightness() for finer control
          set_white();          
      } else {
          // Turn the backlight OFF if the BACKLIGHT_LAYER is NOT active
          rgblight_disable();
      }
  }
}

// Override the process_record_user function to detect layer changes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t current_layer = layer_state; // Get the current active layer
    process_layer_change(current_layer); // Call the function to handle layer changes and backlight
    // Rest of your process_record_user function (if any)
    return true; // Or return false if you want to prevent default key processing
}






/*


LT(layer, kc)	Turn on layer when held, kc when tapped



DF(layer)	Set the base (default) layer until the keyboard loses power
PDF(layer)	Set the base (default) layer in EEPROM
MO(layer)	Momentarily turn on layer when pressed (requires KC_TRNS on destination layer)
OSL(layer)	Momentarily activates layer until a key is pressed. See One Shot Keys for details.
LM(layer, mod)	Momentarily turn on layer (like MO) with mod active as well. Where mod is a mods_bit. Mods can be viewed here. Example Implementation: LM(LAYER_1, MOD_LALT)
TG(layer)	Toggle layer on or off
TO(layer)	Turns on layer and turns off all other layers, except the default layer
TT(layer)	Normally acts like MO unless it's tapped multiple times, which toggles layer on

        #define _BASE 0
        #define _NAV 1
        #define _SYMBOLS 2
        #define _MATH 3
        #define _COLOR 4

        QK_BACKLIGHT_ON
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3(

//,-----------------------------------------------------.                             ,-----------------------------------------------------.
 KC_ESC, KC_Q,            KC_W,            KC_E,           KC_R, KC_T,         KC_0,          KC_U,              KC_I,                KC_O,    KC_P,  KC_QUOT,
//|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
KC_CAPS, KC_A,     LALT_T(KC_S),    CTL_T(KC_D),    SFT_T(KC_F), KC_G,         KC_H, RSFT_T( KC_J),     RCTL_T( KC_K),       RALT_T( KC_L), KC_SCLN,  KC_BSPC,
//|--------+--------+--------+--------+--------+--------|                              |--------+--------+--------+--------+--------+--------|
 KC_TAB, KC_Z, LT(3, KC_X), LT(2, KC_C), LT(_NAV, KC_V), KC_B,         KC_N,   LT(8, KC_M), LT(2, KC_COMM),  LT(3, KC_DOT), KC_SLSH,  KC_ENT,
//|--------+--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------+--------|

                              KC_LGUI,   TG(_NAV),  KC_SPC,                            KC_SPC,   TO(_NAV), XXXXXXX
                             //`--------------------------'  `--------------------------'

  ),

    [_NAV] = LAYOUT_split_3x6_3(
//,-----------------------------------------------------.                    ,-----------------------------------------------------.
KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP,XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
KC_LCTL, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_ENT,
//|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                               KC_LGUI,   TG(_SYMBOLS),  KC_SPC,                            KC_SPC,   TO(_SYMBOLS), XXXXXXX
                                    //`--------------------------'  `--------------------------'
  ),



    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI,   TG(_MATH),  KC_SPC,                            KC_SPC,   TO(_MATH), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),



    [_MATH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_2,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                              KC_LGUI,   TG(_BASE),  KC_SPC,                            KC_SPC,   TO(_COLOR), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),



    [_COLOR] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI,   TG(_NAV),  KC_SPC,                            KC_SPC,   TO(_BASE), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),




    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_1,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI,   TG(_NAV),  KC_SPC,                            KC_SPC,   TO(_MATH), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),




    [6] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI,   TG(_NAV),  KC_SPC,                            KC_SPC,   TO(_MATH), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_LGUI,   TG(_NAV),  KC_SPC,                            KC_SPC,   TO(_MATH), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
