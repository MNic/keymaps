# Keymaps

Personal keymaps

Corne and Planck are zip exports from QMK's online configurator.

`mnic_cajal` is a derivative of the default ortho cajal layout.


## mnic_cajal

### Basic Usage

Keymap location: `mnic_cajal/keymaps/default_ortho/keymap.c`

1. Copy this directory into the `qmk_firmware/keyboards/walletburner/mnic_cajal`
2. Run `make walletburner/mnic_cajal:default_ortho` to compile
3. Open QMK Toolbox
4. 'Open' the newly created .hex file (Typically located at the root of `qmk_firmware`)
5. Get cajal into bootloader
   1. If first time flashing, hit reset button on PBC
   2. Once flashed the first time a Layer(3) click of the Rotary Encoder will put the PCB into bootloader.
6. Flash