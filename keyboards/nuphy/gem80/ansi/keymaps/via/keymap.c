#include "quantum.h"
#include "color.h"
#include "rgblight/rgblight_post_config.h"
#include QMK_KEYBOARD_H
#include "../../ansi.h"

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer Mac
[MAC_BASE] = LAYOUT_tkl_f13_ansi(
	KC_ESC, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	KC_F13, 	MAC_PRTA,	KC_SCRL,	KC_PAUSE,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC,	KC_INS,		KC_HOME,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSLS,	 KC_DEL,	KC_END,		KC_PGDN,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 			KC_ENT,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,
	KC_LCTL,	KC_LOPT,	KC_LCMD,										KC_SPC, 							KC_RCMD,	KC_ROPT,	MO(1),   	KC_RCTL,	KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer Mac Fn
[MAC_FN] = LAYOUT_tkl_f13_ansi(
	_______, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	_______,	MAC_PRT,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,     _______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	RGB_TOG, 	_______, 	_______,  	_______,   	_______,	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,	_______,	_______,	_______,
	_______,	RGB_VAI,   	RGB_VAD,   	RGB_MOD,  	RGB_HUI,   	RGB_SPI,   	RGB_SPD,	_______,   	_______,   	_______,  	_______,	_______, 	 			_______,
	_______,				SIDE_VAI,   SIDE_VAD,   SIDE_MOD,  	SIDE_HUI,   SIDE_SPI,   SIDE_SPD,	_______, 	_______,	_______,	_______,				_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	MO(1),		_______,	_______,    _______,	_______),

// layer win
[WIN_BASE] = LAYOUT_tkl_f13_ansi(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_F13, 	KC_PSCR,	KC_SCRL,	KC_PAUSE,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC,	KC_INS,		KC_HOME,	KC_PGUP,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSLS,	 KC_DEL,	KC_END,		KC_PGDN,
	KC_CAPS,	KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 			KC_ENT,
	KC_LSFT,				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,				KC_RSFT,	KC_UP,
	KC_LCTL,	KC_LGUI,	KC_LALT,										KC_SPC, 							KC_RALT,	KC_RGUI,	MO(3),   	KC_RCTL,	KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer win Fn
[WIN_FN] = LAYOUT_tkl_f13_ansi(
	_______, 	KC_BRID,  	KC_BRIU,  	_______, 	_______,  	_______,  	_______,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	_______,	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,     _______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	RGB_TOG, 	_______, 	_______,  	_______,   	_______,	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,	_______,	_______,	_______,
	_______,	RGB_VAI,   	RGB_VAD,   	RGB_MOD,  	RGB_HUI,   	RGB_SPI,   	RGB_SPD,	_______,   	_______,   	_______,  	_______,	_______, 	 			_______,
	_______,				SIDE_VAI,   SIDE_VAD,   SIDE_MOD,  	SIDE_HUI,   SIDE_SPI,   SIDE_SPD,	_______, 	_______,	_______,	_______,				_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	MO(3),		_______,	_______,    _______,	_______),
    // _______,    KC_BRID,    KC_BRIU,    KC_CALC,   _______,    _______,     _______,   KC_MPRV,    KC_MPLY,     KC_MNXT,   KC_MUTE,    KC_VOLD,    KC_VOLU,     _______,    _______,    _______,
    // _______,    LNK_BLE1,   LNK_BLE2,   LNK_BLE3,  LNK_RF,     _______,     _______,   _______,    _______,     _______,   _______,    _______,	   _______,                 _______,    _______,
    // _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    DEV_RESET,  SLEEP_MODE,              BAT_SHOW,   _______,
    // _______,    _______,    _______,    _______,   _______,    _______,     _______,   _______,    _______,     _______,   _______,    _______,                             _______,    _______,
    // _______,                _______,    _______,   _______,    _______,     BAT_NUM,   _______,    MO(4),       RGB_SPD,   RGB_SPI,    _______,                 _______,    RGB_VAI,    _______,
    // _______,    _______,    _______,                                        _______,                            _______,   MO(3),      _______,                 RGB_MOD,    RGB_VAD,    RGB_HUI),
// layer 5
[4] = LAYOUT_tkl_f13_ansi(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,  	_______,  	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 			_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______, 	_______,	_______,	_______,				_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	MO(1),		_______,	_______,    _______,	_______),
// layer 5
[5] = LAYOUT_tkl_f13_ansi(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,  	_______,  	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 			_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______, 	_______,	_______,	_______,				_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	MO(1),		_______,	_______,    _______,	_______),
// layer 6
[6] = LAYOUT_tkl_f13_ansi(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,  	_______,  	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 			_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______, 	_______,	_______,	_______,				_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	MO(1),		_______,	_______,    _______,	_______),
// layer 7
[7] = LAYOUT_tkl_f13_ansi(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______, 	_______,  	_______,  	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 			_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______, 	_______,	_______,	_______,				_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	MO(1),		_______,	_______,    _______,	_______),
};


// #ifdef RGBLIGHT_ENABLE

const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_BLUE}
);

const rgblight_segment_t PROGMEM mac_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM win_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 3, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    capslock_layer,
    mac_layer,
    win_layer
);

void keyboard_post_init_user(void) {
            // Enable the LED layers
            rgblight_layers = my_rgb_layers;
}

// Enabling and disabling lighting layers for default layer
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, MAC_BASE));
    rgblight_set_layer_state(2, layer_state_cmp(state, WIN_BASE));

    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

// bool led_update_kb(led_t led_state) {
//     if (!led_update_user(led_state)) { return false; }
//     rgblight_set_layer_state(0, led_state.caps_lock);
//     return true;
// }
//
// void keyboard_post_init_kb(void) {
//     rgblight_layers = my_rgb_layers;
//     keyboard_post_init_user();
// }

// #endif
