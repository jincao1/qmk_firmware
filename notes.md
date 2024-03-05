Mac OS custom keys definitons


Borrowed as an example from [qmk_firmware](https://github.com/daaaaaaaaaniel/qmk_firmware/blob/5fbe05ac57eb64dee71572e488b626e51d498c73/keyboards/preonic/keymaps/daaaaaaaaaniel/keymap.c#L327)



```
/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _EXTRA,
  _MIDI
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  MIDI,
  OPTRGHT, // Option-Right Arrow
  OPTLEFT, // Option-Left Arrow
  SHOW_ALL_APP_WINDOWS, // Control-Down Arrow
  KC_MISSION_CONTROL, // AC Desktop Show All Windows
  KC_SPOTLIGHT,
  KC_DICTATION,
  KC_DO_NOT_DISTURB,
  KC_LOCK_SCREEN,
  KC_LAUNCHPAD // AC Desktop Show All Applications
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_SPLT KC_SPOTLIGHT
#define KC_DICT KC_DICTATION
#define KC_DOND KC_DO_NOT_DISTURB
#define KC_LOCK KC_LOCK_SCREEN
#define KC_LPAD KC_LAUNCHPAD
#define ALL_APP SHOW_ALL_APP_WINDOWS

// Sounds
#ifdef AUDIO_ENABLE
  float song_preonic_sound[][2] = SONG(PREONIC_SOUND); // song for switching into MIDI layer
  float song_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);  // song for switching out of MIDI layer (back to QWERTY)
#endif

// Combos
// When both SPACE keys are tapped together, execute ENTER. When both SPACE keys are HELD, activate _EXTRA layer.
enum combos {
//  ADJ_LAYER,
  SPC_ENTER,
};

const uint16_t PROGMEM adj_combo[] = {LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [SPC_ENTER] = COMBO(adj_combo, LT(_EXTRA, KC_ENT)),
//  [ADJ_LAYER] = COMBO(adj_combo, MO(_EXTRA)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  fn  | Ctrl | Opt  | Cmd  |     Lower   |    Raise    | Bksp |   [  |   ]  |   \  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_2x2u(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    RCTL_T(KC_MINS),
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    RCMD_T(KC_BSPC),
  KC_GRV,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, ROPT_T(KC_QUOT),
  SFT_T(KC_ESC), KC_Z, KC_X, KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  /*KC_APFN,*/KC_CAPS, KC_LCTL, KC_LOPT, LCMD_T(KC_DEL), LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), RCMD_T(KC_BSPC), ROPT_T(KC_LBRC), RCTL_T(KC_RBRC), KC_BSLS
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |LockSc|Brght-|Brght+|MsnCtl|Lnchpd| Dict |DoNDst| Rwnd | Play | Ffwd | Mute | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Cmd  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |OLeft | Left |  Up  |Right |ORight| Opt  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Down |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      [      |             | Del  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_2x2u(
  KC_LOCK, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_DICT, KC_DOND, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_RCTL,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RCMD,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, OPTLEFT, KC_LEFT, KC_UP,   KC_RGHT, OPTRGHT, KC_ROPT,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_DOWN, _______, _______, KC_RSFT,
  _______, _______, _______, _______,      KC_LBRC,         _______,      KC_DEL,  KC_LBRC, KC_RBRC, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Ctrl |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |AppSwi|   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Cmd  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Pg Up| Left |  Up  |Right |      |   +  |   *  |   _  |   +  |   [  |   ]  | Opt  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Pg Dn|      |      |      |      |Enter |   =  |ISO # |ISO / | Pg Up| Pg Dn| Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MIDI |      |      |      |             |      ]      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_2x2u(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_RCTL,
  ALL_APP, KC_1,    KC_2,    KC_3,    _______, KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_RCMD,
  KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_PPLS, KC_PAST, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_ROPT,
  KC_PGDN, _______, _______, _______, _______, KC_PENT, KC_PEQL, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_RSFT,
  MIDI,    _______, _______, _______,      _______,         KC_RBRC,      KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Extra Layer (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  Up  |      |      |      |      |      |  Up  |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      | Debug|
 * `-----------------------------------------------------------------------------------'
 */
[_EXTRA] = LAYOUT_preonic_2x2u(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  _______, _______, KC_UP,   _______, _______, _______, _______, _______, KC_UP,   _______, _______, KC_DEL,
  _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,     _______,          _______,      _______, _______, _______, DEBUG
),

/* MIDI
 * ,-----------------------------------------------------------------------------------.
 * |  C0  |  D♭0 |  D0  |  E♭0 |  E0  |  F0  |  G♭0 |  G0  |  A♭0 |  A0  |  B♭0 |  B0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C1  |  D♭1 |  D1  |  E♭1 |  E1  |  F1  |  G♭1 |  G1  |  A♭1 |  A1  |  B♭1 |  B1  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  C2  |  D♭2 |  D2  |  E♭2 |  E2  |  F2  |  G♭2 |  G2  |  A♭2 |  A2  |  B♭2 |  B2  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  C3  |  D♭3 |  D3  |  E♭3 |  E3  |  F3  |  G♭3 |  G3  |  A♭3 |  A3  |  B♭3 |  B3  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Qwerty|      | Vel-1| Vel+1| Pitch Bend+ | Pitch Bend- |Oct-1 |Oct+1 |Note-1|Note+1|
 * `-----------------------------------------------------------------------------------'
 */
[_MIDI] = LAYOUT_preonic_2x2u(
  MI_C,    MI_Db,   MI_D,    MI_Eb,   MI_E,    MI_F,    MI_Gb,   MI_G,    MI_Ab,   MI_A,    MI_Bb,   MI_B,
  MI_C_1,  MI_Db_1, MI_D_1,  MI_Eb_1, MI_E_1,  MI_F_1,  MI_Gb_1, MI_G_1,  MI_Ab_1, MI_A_1,  MI_Bb_1, MI_B_1,
  MI_C_2,  MI_Db_2, MI_D_2,  MI_Eb_2, MI_E_2,  MI_F_2,  MI_Gb_2, MI_G_2,  MI_Ab_2, MI_A_2,  MI_Bb_2, MI_B_2,
  MI_C_3,  MI_Db_3, MI_D_3,  MI_Eb_3, MI_E_3,  MI_F_3,  MI_Gb_3, MI_G_3,  MI_Ab_3, MI_A_3,  MI_Bb_3, MI_B_3,
  QWERTY, _______,  MI_VELD, MI_VELU,     MI_BENDD,         MI_BENDU,     MI_OCTD, MI_OCTU, MI_TRNSD, MI_TRNSU
)

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
// [_ADJUST] = LAYOUT_preonic_2x2u(
//   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//   _______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
//   _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
//   _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
//   _______, _______, _______, _______,     _______,          _______,      _______, _______, _______, _______
// )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            // set_single_persistent_default_layer(_QWERTY);
            layer_off(_MIDI);
            layer_move(_QWERTY);
            stop_all_notes();
            PLAY_SONG(song_plover_gb);
          }
          return false;
          break;
        case MIDI:
          if (record->event.pressed) {
            layer_on(_MIDI);
            stop_all_notes();
            PLAY_SONG(song_preonic_sound);
          }
          return false;
          break;
//         case LOWER:
//           if (record->event.pressed) {
//             layer_on(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _EXTRA);
//           } else {
//             layer_off(_LOWER);
//             update_tri_layer(_LOWER, _RAISE, _EXTRA);
//           }
//           return false;
//           break;
//         case RAISE:
//           if (record->event.pressed) {
//             layer_on(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _EXTRA);
//           } else {
//             layer_off(_RAISE);
//             update_tri_layer(_LOWER, _RAISE, _EXTRA);
//           }
//           return false;
//           break;
/*-----------------------*/
/*-------Opt Right-------*/
// For faster arrow key-like text navigation
        case OPTRGHT:
          if (record->event.pressed) {
            // when keycode OPTRGHT is pressed
            register_code(KC_LOPT);  // press the Opt key
            register_code(KC_RIGHT);  // press the Right Arrow key
          } else {
            // when keycode OPTRGHT is released
            unregister_code(KC_RIGHT);  // release Right Arrow key
            unregister_code(KC_LOPT);  // release Opt key
          }
          break;
/*-----------------------*/
/*-------Opt Left-------*/
// For faster arrow key-like text navigation
        case OPTLEFT:
          if (record->event.pressed) {
            // when keycode OPTLEFT is pressed
            register_code(KC_LOPT);  // press the Opt key
            register_code(KC_LEFT);  // press the Left Arrow key
          } else {
            // when keycode OPTLEFT is released
            unregister_code(KC_LEFT);  // release Left Arrow key
            unregister_code(KC_LOPT);  // release Opt key
          }
          break;
/*--------------Control Down--------------*/
/*---Show all windows of the front app.---*/
        case SHOW_ALL_APP_WINDOWS:
          if (record->event.pressed) {
            // when keycode SHOW_ALL_APP_WINDOWS is pressed
            register_code(KC_LCTL);  // press the Opt key
            register_code(KC_DOWN);  // press the Down Arrow key
          } else {
            // when keycode SHOW_ALL_APP_WINDOWS is released
            unregister_code(KC_DOWN);  // release Down Arrow key
            unregister_code(KC_LCTL);  // release Opt key
          }
          break;
// macOS key codes from /u/Archite - https://gist.github.com/archite/6021f8204f147ff8b756f73a12bc778a
        case KC_MISSION_CONTROL:
          if (record->event.pressed) {
            host_consumer_send(0x29F);
          } else {
            host_consumer_send(0);
          }
          return false;
          break;
        case KC_SPOTLIGHT:
          if (record->event.pressed) {
            host_consumer_send(0x221);
          } else {
            host_consumer_send(0);
          }
          return false;
          break;
        case KC_DICTATION:
          if (record->event.pressed) {
            host_consumer_send(0xCF);
          } else {
            host_consumer_send(0);
          }
          return false;
          break;
        case KC_DO_NOT_DISTURB:
          if (record->event.pressed) {
            host_system_send(0x9B);
          } else {
            host_system_send(0);
          }
          return false;
          break;
        case KC_LOCK_SCREEN:
          if (record->event.pressed) {
            host_consumer_send(0x19E);
          } else {
            host_consumer_send(0);
          }
          return false;
          break;
        case KC_LAUNCHPAD:
          if (record->event.pressed) {
            host_consumer_send(0x2A0);
          } else {
            host_system_send(0);
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_EXTRA);
            } else {
                layer_off(_EXTRA);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

/*
 * bool music_mask_user(uint16_t keycode) {
 *   switch (keycode) {
 *     case RAISE:
 *     case LOWER:
 *       return false;
 *     default:
 *       return true;
 *   }
 * }
 */
```
