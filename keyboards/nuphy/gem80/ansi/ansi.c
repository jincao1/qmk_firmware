/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "user_kb.h"
#include "ansi.h"
#include "usb_main.h"
#include "mcu_pwr.h"

extern bool            f_rf_sw_press;
extern bool            f_sleep_show;
extern bool            f_dev_reset_press;
extern bool            f_bat_num_show;
extern bool            f_rgb_test_press;
extern bool            f_bat_hold;
extern uint16_t        no_act_time;
extern uint8_t         rf_sw_temp;
extern uint16_t        rf_sw_press_delay;
extern uint16_t        rf_linking_time;
extern uint16_t        sleep_time_delay;
extern user_config_t   user_config;
extern DEV_INFO_STRUCT dev_info;
extern uint8_t         rf_blink_cnt;

/* qmk process record */
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    no_act_time     = 0;
    rf_linking_time = 0;

    if (!process_record_user(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case RF_DFU:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) return false;
                uart_send_cmd(CMD_RF_DFU, 10, 20);
            }
            return false;

        case LNK_USB:
            if (record->event.pressed) {
                break_all_key();
            } else {
                dev_info.link_mode = LINK_USB;
                uart_send_cmd(CMD_SET_LINK, 10, 10);
            }
            return false;

        case LNK_RF:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_RF_24;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case LNK_BLE1:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_BT_1;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case LNK_BLE2:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_BT_2;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case LNK_BLE3:
            if (record->event.pressed) {
                if (dev_info.link_mode != LINK_USB) {
                    rf_sw_temp    = LINK_BT_3;
                    f_rf_sw_press = 1;
                    break_all_key();
                }
            } else if (f_rf_sw_press) {
                f_rf_sw_press = 0;

                if (rf_sw_press_delay < RF_LONG_PRESS_DELAY) {
                    dev_info.link_mode   = rf_sw_temp;
                    dev_info.rf_channel  = rf_sw_temp;
                    dev_info.ble_channel = rf_sw_temp;
                    uart_send_cmd(CMD_SET_LINK, 10, 20);
                }
            }
            return false;

        case MAC_DND:
            if (record->event.pressed) {
                host_system_send(0x9b);
            } else {
                host_system_send(0);
            }
            return false;
        // 任务调度按键
        case MAC_TASK:
            if (record->event.pressed) {
                host_consumer_send(0x029F);
            } else {
                host_consumer_send(0);
            }
            return false;
        // 搜索按键
        case MAC_SEARCH:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_SPACE);
                wait_ms(50);
                unregister_code(KC_LGUI);
                unregister_code(KC_SPACE);
            }
            return false;
        // 语音按键
        case MAC_VOICE:
            if (record->event.pressed) {
                host_consumer_send(0xcf);
            } else {
                host_consumer_send(0);
            }
            return false;
        // 启动台
        case MAC_DNT:
            if (record->event.pressed) {
                host_consumer_send(0x02A0);
            } else {
                host_consumer_send(0);
            }
            return false;
        case MAC_PRT:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_3);
                wait_ms(50);
                unregister_code(KC_3);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            return false;
        case MAC_PRTA:
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LSFT);
                register_code(KC_4);
                wait_ms(50);
                unregister_code(KC_4);
                unregister_code(KC_LSFT);
                unregister_code(KC_LGUI);
            }
            return false;

            extern void light_speed_contol(uint8_t fast);
            extern void light_level_control(uint8_t brighten);
            extern void side_colour_control(uint8_t dir);
            extern void side_mode_control(uint8_t dir);


        case SIDE_VAI:
            if (record->event.pressed) {
                side_light_control(1);
            }
            return false;

        case SIDE_VAD:
            if (record->event.pressed) {
                side_light_control(0);
            }
            return false;

        case SIDE_MOD:
            if (record->event.pressed) {
                side_mode_control(1);
            }
            return false;

        case SIDE_HUI:
            if (record->event.pressed) {
                side_colour_control(1);
            }
            return false;

        case SIDE_SPI:
            if (record->event.pressed) {
                side_speed_control(1);
            }
            return false;

        case SIDE_SPD:
            if (record->event.pressed) {
                side_speed_control(0);
            }
            return false;

        case DEV_RESET:
            if (record->event.pressed) {
                f_dev_reset_press = 1;
                break_all_key();
            } else {
                f_dev_reset_press = 0;
            }
            return false;

        case SLEEP_MODE:
            if (record->event.pressed) {
                user_config.sleep_enable = !user_config.sleep_enable;
                f_sleep_show             = 1;
                eeconfig_update_kb_datablock(&user_config);
            }
            return false;

        case BAT_SHOW:
            if (record->event.pressed) {
                f_bat_hold = !f_bat_hold;
            }
            return false;

        case BAT_NUM:
            f_bat_num_show = record->event.pressed;
            return false;

        case RGB_TEST:
            f_rgb_test_press = record->event.pressed;
            return false;

        case LINK_TO:
            if (record->event.pressed) {
                uint16_t mask = LINK_TIMEOUT ^ LINK_TIMEOUT_ALT;
                user_config.rf_link_timeout ^= mask; // XOR swap
                eeconfig_update_kb_datablock(&user_config);
            }
            return false;

        case RGB_VAI: // ensure LED powers on with brightness increase
            if (record->event.pressed) {
                pwr_rgb_led_on();
            }
            return true;

        case KB_SLP:
            if (record->event.pressed) {
                uint16_t mask = (100 * 30) ^ SLEEP_TIME_DELAY; // 30s or default
                sleep_time_delay ^= mask; // XOR swap
            }
            return false;

        default:
            return true;
    }
    return true;
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }

    if (f_bat_num_show || f_bat_hold) {
        bat_pct_led_kb();
    }

    if (debug_enable) {
        user_set_rgb_color(56, 0x80, 0x00, 0x00);
    }

    // light up corresponding BT mode key during connection
    if (rf_blink_cnt && dev_info.link_mode >= LINK_BT_1 && dev_info.link_mode <= LINK_BT_3) {
        user_set_rgb_color(30 - dev_info.link_mode, 0, 0, 0x80);
    }

    // power down unused LEDs
    led_power_handle();

    return true;
}

/* qmk keyboard post init */
void keyboard_post_init_kb(void) {
    gpio_init();
    rf_uart_init();
    wait_ms(500);
    rf_device_init();

    break_all_key();
    dial_sw_fast_scan();
    load_eeprom_data();
    keyboard_post_init_user();
}

/* qmk housekeeping task */
void housekeeping_task_kb(void) {
    timer_pro();

    uart_receive_pro();

    uart_send_report_repeat();

    dev_sts_sync();

    long_press_key();

    dial_sw_scan();

    side_led_show();

    sleep_handle();
}
