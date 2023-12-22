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
// #include "bsp/board.h"
#include "tusb.h"

extern void hid_app_task(void);

void setup()
{

}

int main()
{
    stdio_init_all();
    // board_init(); // this is part of tinyusb examples todo: figure out what we need and move over
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
