# USB Keyboard Adapter for Atari 400/800/xl/xe 8-bits

This USB keyboard adapter is based on a Raspberry Pi PICO MCU using the TinyUSB library. The PICO monitors the 6-bit keycode address that is scanned at the HSYNC rate by the POKEY chip. The PICO returns the keystate for each keycode. The keystates are updated by the HID callback functions when a USB keyboard event is handled. The Atari POKEY-side interface is implemented using a PIO state machine and two DMA channels, requiring no processor interaction. The USB interface is handled in software by TinyUSB. 

## PICO peripherals
One PIO state machine
Two DMA channels
USB port
8 GPIO pins

GPIO's 2-7 are connected to POKEY /K0-/K5.
GPIO 10 (and 11) are connected to the POKEY /KR1 (and /KR2) inputs and the PIO SM controls their direction. In input mode, the outputs present hi-z to the Atari pull up resistors. In output mode, they are already set to zero and pull down the output to ground. This scheme mimics and open drain or open collector action.


