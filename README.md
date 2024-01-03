USB Keyboard Adapter for Atari 400/800/xl/xe 8-bits

This USB keyboard adapter is based on a Raspberry Pi PICO MCU using the TinyUSB library. The PICO monitors the 6-bit keycode address that is scanned at the HSYNC rate by the POKEY chip. The PICO returns the keystate for each keycode. The keystates are updated by the HID callback functions when a USB keyboard event is handled. The Atari POKEY-side interface is implemented using a PIO state machine and two DMA channels, requiring no processor interaction. The USB interface is handled in software by TinyUSB. 

PICO peripherals in use:
One PIO state machine
Two DMA channels
USB port
8 GPIO pins

GPIO's 2-7 are connected to POKEY /K0-/K5.
GPIO 10 (and 11) drives a 2n2222 transistor in open collector configuration connected to the POKEY /KR1 (and /KR2) inputs. The Atari includes the necessary pull up resistor.
