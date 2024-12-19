# Non-Stock Customizations & Fixes

The following customizations/changes/fixes were applied on top of NuPhy's stock firmware. It includes various personal enhancements and bug fixes.

## Customizations

- `Fn + B` when held temporarily displays the current battery percentage on the F and number row.
The F row represents the 10s percentage and number row the ones. Example, 35% will light `F3` and `5`.
- `Fn + \` turns on percent battery display as well as the stock side LED indicator. Side LED battery gauge steps are enhanced, turning off 1 LED every 20%.
- Battery indicator colours: green for 100% to 81%, yellow for 80% to 41%, orange/amber for 40% to 21%, and red for 20% and below.
- `Fn + M + Z` to toggle the RF disconnect sleep timer between `5s` and `120s` (NuPhy default). Default is set to `5s`. This persist through restarts.
This sets how long the board tries to connect (left light blinking) before giving up.
- `Fn + M + S` toggles idle sleep timer between `30s` and default `360s`. This is temporary.
- `Fn + M + D` toggles QMK debugging. Don't turn this on when not connected to QMK toolbox.
The letter `D` will light up red when enabled.
- Side indicators will flash red for 0.5s when board enters sleep mode, as an indicator.
This is a deep sleep state. There are no indicators in other sleep modes.
- Bluetooth connection indicators will be lit blue when establishing connection. This lights the corresponding
BT mode key. No indicator for RF as the sidelight is a different colour.
- Default startup LED brightness set to zero and side led set to lowest brightness. This is because I don't use LEDs so I don't need to toggle them off when resetting the board or flashing new firmware.
- 3ms debounce instead of 2ms (potential stability)
- 3 sleep modes (inspired by @adi4086) - Toggle sleep mode button moved to `Fn + M + ]`.
  - Deep Sleep (NRF off, MCU off, LED off) - lowest power consumption. This is the default. Right indicator blinks green.
  - Light Sleep (NRF off, LED off) - no real reason to use this, but might wake up quicker. Right indicator blinks yellow.
  - No Sleep - for those that want their board to always be on... Right indicator blinks red.
- Keyboard will never go to deep sleep in USB mode. This seems to cause issues on wake and I don't have a solution. I'm expecting that the device is powered and if it's not the keyboard would reset anyway.
- Keyboard won't go to deep sleep if charging on wireless mode as charging interrupts the MCU causing it to sleep and wake repeatedly. To restore the proper sleep mode you must wake the board while it's off the charger.
- Press and hold RGB matrix LED brightness up for `1.5s` to turn on RGB matrix if it was previously off. This is by choice to prevent accidentally turning on backlight when keyboard is being mashed in the NuFolio case for myself.

## Fixes

- Fix keyboard randomly crashing/freezing.
- Fix keyboard not sleeping properly and draining battery. This version sleeps the processor and uses almost no battery on sleep.
- Fix LED lights not powering down when not used. This increases battery life around 50-70% when LEDs aren't used.
- Fix keystrokes being lost on wake. Wake keystrokes will appear after a very short delay while board re-establishes connection. BT wake keys may not be as reliable as the 2.4ghz dongle.  
  This is achieved through a buffer of 64 key actions (key down and key up are 2 actions). The buffer is cleared if connection is not established within 1s after the last action.
  Key events after the buffer is full will also be dropped.
- Enhance keyboard reports transmission logic to greatly reduce stuck/lost key strokes. It may still occasionally drop/repeat keys but it's rare.
- Slightly enhanced sidelight refresh intervals for smoother animations.
- Reduced unused side LED tables to save a chunk of memory. This may be essential to the RF queue as the board only has 16kb memory available - the queue alone uses over 1.2kb.

## VIA

This firmware is still compatible with VIA. Grab the latest/most relevant [VIA JSON](/keyboards/nuphy/air75_v2/ansi/keymaps/via/air75_v2_via_v3.json) and load it into VIA using the *Design* tab. This is used the same way as stock NuPhy. I'm not a Mac user so this is default behaviour placed here for reference.

The following keys are unnamed as they are QMK key combinations. They will show as follows in VIA as there is no way to customize these names in VIA.

| Key Code     | Function               |
| ------------ | ---------------------- |
| `0xc1`       | Launch Mission Control |
| `0xc2`       | Launchpad              |
| `G(KC_SPC)`  | Mac Search             |
| `G(S(KC_4))` | Mac Print Screen Area  |
| `G(S(KC_3))` | Mac Print Screen Whole |

## RF Firmware

This firmware is built and tested against NuPhy's RF firmware `v1.0.3`. Refer to the [RF Firmware folder](rf_firmware) if you want to get the update.
The experience you get with the firmware may vary from mine and is dependent on various external factors.

## Author

[@jincao1](https://github.com/jincao1)