#include "quantum.h"

#include QMK_KEYBOARD_H
#include "keymap_spanish.h"


/*
tap dance
https://docs.qmk.fm/features/tap_dance#how-to-use
*/
// Tap Dance declarations
enum {
    ESC_CAPS,
    DOT_2x,
    QUOT_2x,
    COMA_2x,
    SOMTH_BOOT,
    SLASH_BCKSL,
    WEIRD,
    E_ALT_TAB,
    A_AT

};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [DOT_2x] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_SEMICOLON)),
    [QUOT_2x] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, S(KC_QUOT)),
    [COMA_2x] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SEMICOLON),
    [SOMTH_BOOT] = ACTION_TAP_DANCE_DOUBLE(KC_1, QK_BOOT),
    [SLASH_BCKSL] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_BACKSLASH),
    [WEIRD] = ACTION_TAP_DANCE_DOUBLE(KC_K, QK_BOOT),
    [E_ALT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_E, A(KC_TAB)),
    [A_AT] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_AT),
    
};

/*
const uint16_t PROGMEM test_combo1[] = {KC_A, KC_B, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_C, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, KC_X),
    COMBO(test_combo2, S(KC_Z)), // keycodes with modifiers are possible too!
};*/



enum combos { 
  A_S,
  D_F,
  C_V_B
  
};


const uint16_t PROGMEM test_chord [] = { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM test_chord2 [] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM test_chord3 [] = { KC_C, KC_V,KC_B, COMBO_END};

combo_t key_combos[CHORD_COUNT] = {
  [A_S] = COMBO(test_chord, KC_X),
  [D_F] = COMBO(test_chord2, KC_X),
  [C_V_B] = COMBO(test_chord3, KC_X),
};


/*




enum combos { 
  A_S,
  D_F,
  C_V_B
  
};


const uint16_t PROGMEM test_chord [] = { KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM test_chord2 [] = { KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM test_chord3 [] = { KC_C, KC_V,KC_B, COMBO_END};

combo_t key_combos[CHORD_COUNT] = {
  [A_S] = COMBO(test_chord, KC_X),
  [D_F] = COMBO(test_chord2, KC_X),
  [C_V_B] = COMBO(test_chord3, KC_X),
};









*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_split_3x6_3(

TD(ESC_CAPS), KC_Q,        KC_W,   KC_E,        KC_R,    KC_T,                    KC_Y,        KC_U,         KC_I,             KC_O,           KC_P,    KC_BSPC,
          
KC_TAB,       TD(A_AT),  LALT_T(KC_S),   CTL_T(KC_D),  SFT_T(KC_F),   KC_G,                    KC_H, RSFT_T(KC_J),   RCTL_T(KC_K),  LALT_T( KC_L),       ES_NTIL,  TD(QUOT_2x),
          
XXXXXXX,    KC_Z,           KC_X,          KC_C,          KC_V,    KC_B,                    KC_N,       KC_M,     TD(COMA_2x),     TD(DOT_2x), TD(SLASH_BCKSL),  KC_ENT,
          
                    XXXXXXX,  LT(_MATH,XXXXXXX),   LT(_NAV, KC_SPC),                     LT(_SYMBOLS, KC_SPC),   TO(_SYMBOLS), LT(_WEIRD,XXXXXXX)
  ),



    [_NAV] = LAYOUT_split_3x6_3(

  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP,XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  KC_LCTL, XXXXXXX, XXXXXXX, KC_C, KC_V, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|

                               KC_LGUI,   TO(_BASE),  KC_SPC,                            KC_SPC,   TO(_SYMBOLS), KC_1
                                    //`--------------------------'  `--------------------------'

  ),


  [_SYMBOLS] = LAYOUT_split_3x6_3(
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, XXXXXXX,  KC_GRV,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LBRC, KC_RBRC, TD(COMA_2x), TD(DOT_2x),  TD(SLASH_BCKSL), KC_ASTR,
                              KC_LGUI,   TO(_BASE),  KC_SPC,                            KC_SPC,   TO(_MATH), KC_2

  ),

/*kkk
bbbbcccbbccccccccccccccccvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvjjjjjpppññoiiouuiuuuuupppppooo
Ñ.Ñ.Ñ"'""bbbbbvvccxxzzzzcccc0ccccvvvvbbbccczzzzzzzzzzzzazasssddcd


       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, TO(_NAV),

*/

                
    [_MATH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LPRN,    KC_7,    KC_8,    KC_9, KC_ASTR, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_RPRN,    KC_4,    KC_5,    KC_6, KC_PLUS, KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_EQUAL,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX,   TO(_BASE),  XXXXXXX,                            KC_SPC,   KC_0, KC_DOT
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
                              XXXXXXX,   TO(_BASE),  KC_8,                            KC_SPC,   TO(_BASE), XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),


  [_WEIRD] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX,   TO(_BASE),  KC_9,                            TO(_TEST),   QK_BOOT, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
      
  [_TEST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,                      KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,                      KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,                      KC_1, KC_1, KC_1, KC_1, KC_1, KC_1,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              KC_1,   TO(_BASE),  KC_1,                            KC_1,   KC_1, KC_1
                                      //`--------------------------'  `--------------------------'
  ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif






























//                 COLORS

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




