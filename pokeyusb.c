// standard libs
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"

//hardware libs
#include "hardware/dma.h"
#include "hardware/pio.h"

//PIOs
#include "kbd.pio.h"

//TinyUSB
#include "tusb.h"

PIO pioblk_keyboard = pio0;
#define SM_KB 0
#define PIN_K0   2
#define PIN_KR1  10

extern void hid_app_task(void);

__aligned(256) uint8_t keyboard_lut[64] = { [0 ... 63] = 0 };

int chan_kb_addr, chan_kb_data;
dma_channel_config cfg_kb_addr, cfg_kb_data;

void setup()
{
  // DMA
      /** 
     * keyboard PIO - read 6 bits of keycode scanning (/K0-/K5) 
     * and output 2 bits of response (/KR0, /KR1)
     * 
     * from Section 3.5.6.1 in RP2040 datasheet:
     * For each GPIO, PIO collates the writes from all four state machines, 
     * and applies the write from the highest-numbered state machine. 
     * This occurs separately for output levels and output values — 
     * it is possible for a state machine to change both the level and 
     * direction of the same pin on the same cycle (e.g. via simultaneous
     * SET and side-set), or for one state  machine to change a GPIO’s 
     * direction while another changes that GPIO’s level.
    */

    uint offset = pio_add_program(pioblk_keyboard, &kbd_program);
    printf("\nLoaded keyboard program at %d\n\n", offset);
    kbd_program_init(pioblk_keyboard, SM_KB, offset, PIN_K0, PIN_KR1);
    
    pio_sm_put(pioblk_keyboard, SM_KB, (uintptr_t)keyboard_lut >> KLINES);
    pio_sm_exec_wait_blocking(pioblk_keyboard, SM_KB, pio_encode_pull(false, true));
    pio_sm_exec_wait_blocking(pioblk_keyboard, SM_KB, pio_encode_mov(pio_y, pio_osr));
    pio_sm_exec_wait_blocking(pioblk_keyboard, SM_KB, pio_encode_out(pio_null, 1)); 
    pio_sm_exec_wait_blocking(pioblk_keyboard, SM_KB, pio_encode_set(pio_pins, 0));
    pio_sm_set_enabled(pioblk_keyboard, SM_KB, true);

    chan_kb_addr = dma_claim_unused_channel(true);
    cfg_kb_addr = dma_channel_get_default_config(chan_kb_addr);

    chan_kb_data = dma_claim_unused_channel(true);
    cfg_kb_data = dma_channel_get_default_config(chan_kb_data);
 
    channel_config_set_read_increment(&cfg_kb_data,false);
    channel_config_set_write_increment(&cfg_kb_data,false);
    channel_config_set_dreq(&cfg_kb_data, pio_get_dreq(pioblk_keyboard, SM_KB, true)); // mux PIO
    channel_config_set_chain_to(&cfg_kb_data, chan_kb_addr);
    channel_config_set_transfer_data_size(&cfg_kb_data, DMA_SIZE_8);
    channel_config_set_irq_quiet(&cfg_kb_data, true);
    channel_config_set_enable(&cfg_kb_data, true);
    dma_channel_configure(
        chan_kb_data,                          // Channel to be configured
        &cfg_kb_data,                        // The configuration we just created
        &pioblk_keyboard->txf[SM_KB],                   // The initial write address
        keyboard_lut,                      // The initial read address
        1,                                  // Number of transfers; in this case each is 1 byte.
        false                               // do not Start immediately.      
      );

    channel_config_set_read_increment(&cfg_kb_addr,false);
    channel_config_set_write_increment(&cfg_kb_addr,false);
    channel_config_set_dreq(&cfg_kb_addr, pio_get_dreq(pioblk_keyboard, SM_KB, false)); // mux PIO
    channel_config_set_chain_to(&cfg_kb_addr, chan_kb_data);
    channel_config_set_transfer_data_size(&cfg_kb_addr, DMA_SIZE_32);
    channel_config_set_irq_quiet(&cfg_kb_addr, true);
    channel_config_set_enable(&cfg_kb_addr, true);
    dma_channel_configure(
        chan_kb_addr,                          // Channel to be configured
        &cfg_kb_addr,                        // The configuration we just created
        &dma_channel_hw_addr(chan_kb_data)->read_addr,   // The initial write address
        &pioblk_keyboard->rxf[SM_KB],            // The initial read address
        1,                                  // Number of transfers; in this case each is 1 byte.
        true                               // do not Start immediately.      
      );

}

int main()
{
    stdio_init_all();
    printf("\nPICO-POKEY USB\n");

    setup();

    // tinyusb: init host stack on configured roothub port
    tuh_init(BOARD_TUH_RHPORT);

    while (true)
    {
        // tinyusb: host task
        tuh_task();
    }

    return 0;
}


//--------------------------------------------------------------------+
// TinyUSB Callbacks
//--------------------------------------------------------------------+

void tuh_mount_cb(uint8_t dev_addr)
{
  // application set-up
  printf("A device with address %d is mounted\r\n", dev_addr);
}

void tuh_umount_cb(uint8_t dev_addr)
{
  // application tear-down
  printf("A device with address %d is unmounted \r\n", dev_addr);
}
