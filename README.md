# Corne Keyboard Custom Layout

This repository contains my custom keymap and layout configuration for the Corne (CRKBD) keyboard, supporting both QMK and ZMK firmware builds through automated CI/CD.

## About the Corne Keyboard

The Corne (CRKBD) is a popular 42-key split ortholinear keyboard designed by foostan. It features:

- **42 keys total** (21 per half)
- **3x6 column staggered layout** with 3 thumb keys per side
- **Split design** for ergonomic typing
- **OLED displays** (optional)
- **Rotary encoders** (optional)
- **Hot-swap sockets** support
- **Wireless capability** (with compatible controllers like nice!nano)

The compact layout encourages the use of layers and custom key combinations, making it highly customizable for different workflows.

## Firmware Options

### QMK Firmware
[QMK (Quantum Mechanical Keyboard)](https://qmk.fm/) is a feature-rich, open-source keyboard firmware written in C. It offers:

- **Extensive customization** with macros, tap dance, combos
- **Wide hardware support** including RGB, rotary encoders, OLED
- **Active development** with regular updates
- **USB connectivity** (wired operation)
- **Large community** and documentation

### ZMK Firmware
[ZMK (Zephyr Mechanical Keyboard)](https://zmk.dev/) is a modern keyboard firmware built on the Zephyr RTOS. Key features:

- **Wireless-first design** with Bluetooth Low Energy
- **Low power consumption** for battery-powered keyboards
- **Modern architecture** with clean configuration files
- **Growing ecosystem** specifically for wireless split keyboards
- **Easy configuration** through device trees and Kconfig

## My Layout Philosophy

This custom layout is designed for:

- **Programming workflow** with easy access to symbols and navigation
- **Vim-inspired** navigation on layers
- **Efficient thumb usage** for modifiers and layer switching
- **Minimal finger movement** with strategic key placement
- **Cross-platform compatibility** (Windows, macOS, Linux)

## Repository Structure

```
├── .github/workflows/
│   └── build.yml          # CI/CD pipeline for both QMK and ZMK
├── qmk/                   # QMK keymap files
│   ├── keymap.c          # Main keymap definition
│   ├── config.h          # QMK configuration
│   └── rules.mk          # Build rules and features
├── zmk/                   # ZMK configuration files
│   ├── corne.keymap      # ZMK keymap definition
│   └── corne.conf        # ZMK configuration
└── README.md             # This file
```

## Compilation

### Automated Builds (Recommended)

The repository includes GitHub Actions workflow that automatically builds both QMK and ZMK firmware:

- **Triggers**: Push to `main`/`develop`, pull requests, manual dispatch
- **QMK build**: Generates `.hex` files and keymap JSON
- **ZMK build**: Generates `.uf2` files for left and right halves
- **Artifacts**: Available for download for 30 days

### Local Compilation

#### QMK
```bash
# Install QMK CLI
pip3 install qmk

# Setup QMK (first time)
qmk setup

# Clone this repo to QMK keymaps directory
git clone <this-repo> keyboards/crkbd/keymaps/custom

# Compile firmware
qmk compile -kb crkbd -km custom

# Export keymap visualization
qmk c2json -kb crkbd -km custom > keymap.json
```

#### ZMK
```bash
# Install west
pip3 install west

# Initialize ZMK workspace
west init -m https://github.com/zmkfirmware/zmk.git zmk
cd zmk
west update

# Copy config files to config directory
cp path/to/this/repo/zmk/* config/

# Build firmware
west build -d build/left -b nice_nano_v2 -- -DSHIELD=corne_left
west build -d build/right -b nice_nano_v2 -- -DSHIELD=corne_right
```

## Flashing Instructions

### QMK (Wired)
1. Put keyboard in bootloader mode (reset button or key combination)
2. Flash with: `qmk flash -kb crkbd -km custom`
3. Or use QMK Toolbox with the generated `.hex` file

### ZMK (Wireless)
1. Put nice!nano in bootloader mode (double-tap reset)
2. Drag and drop the `.uf2` file to the mounted drive
3. Flash both left and right halves with their respective files

## Hardware Compatibility

### QMK Compatible Controllers
- Pro Micro
- Elite-C
- Proton-C
- RP2040-based controllers

### ZMK Compatible Controllers
- nice!nano v1/v2
- nRFMicro
- Other nRF52-based controllers

## Customization

To customize this layout:

1. **Fork this repository**
2. **Modify keymap files** in `qmk/` or `zmk/` directories
3. **Push changes** to trigger automatic builds
4. **Download artifacts** from GitHub Actions
5. **Flash to your keyboard**

## Contributing

Feel free to open issues or pull requests if you find bugs or have suggestions for improvements!

## License

This project is licensed under the GPL v2 License - see the QMK and ZMK project licenses for details.
