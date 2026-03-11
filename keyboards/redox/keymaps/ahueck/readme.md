# The ahueck keymap for Redox/rev1

Further information for the keyboard specifics: [Redox repository](https://github.com/mattdibi/redox-keyboard) and [Redox qmk firmware](https://github.com/qmk/qmk_firmware/tree/master/keyboards/redox)

## Flashing the device
See also [Github CI](.github/workflows/basic-ci.yml)

Always do the flashing procedure for both sides.
Reset button (pinhole) is on the underside of each half, respectively.

### 1. Setup CLI
    - python3 -m pip install --user qmk

### 2. Setup firmware
    - qmk setup -H ${QMK_HOME}

### 3. Setup keymap
    1. cd ${QMK_HOME}/keyboards/redox/keymaps/
    2. git clone https://github.com/ahueck/redox-keymap.git ahueck
    3. qmk compile -kb redox/rev1 -km ahueck

### 4. Flash
    1. Flashing 
        - qmk flash -kb redox/rev1 -km ahueck
        - From CI file: qmk flash redox_rev1_base_ahueck.hex
    2. Repeat step 2. for second half (switch USB connection)

- Modem manager may need special handling, see https://docs.qmk.fm/#/faq_build?id=linux-udev-rules, or, e.g., `sudo systemctl stop ModemManager.service`
  - Restart modem manager if applicable

#### Useful links
[Online config](https://config.qmk.fm/#/redox/rev1/base/LAYOUT)
 
##### Key related
- [Keycodes basic](https://docs.qmk.fm/#/keycodes)

