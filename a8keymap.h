#ifndef _A8KEYMAP_H
#define _A8KEYMAP_H

// https://www.atariarchives.org/c3ba/kcindex.php

// http://krap.pl/mirrorz/atari/homepage.ntlworld.com/kryten_droid/Atari/800XL/atari_hw/pokey.htm#Key%20scan%20circuit
//  	    !K0	!K1	!K2	!K3	!K4	!K5
// CNTL	    1	1	1	1	1	1           0x3f
// SHIFT	1	1	1	1	0	1           0x2f
// BRK	    1	1	1	1	0	0           0x0f


#include <stdint.h>

extern uint8_t a8keymap[128];

#define A8_KEY_L               0
#define A8_KEY_J               1
#define A8_KEY_SEMICOLON               2
#define A8_KEY_K               5
#define A8_KEY_PLUS               6
#define A8_KEY_ASTERISK               7
#define A8_KEY_O               8
#define A8_KEY_P               10
#define A8_KEY_U               11
#define A8_KEY_RETURN               12
#define A8_KEY_I               13
#define A8_KEY_MINUS               14
#define A8_KEY_EQUAL               15
#define A8_KEY_V               16
#define A8_KEY_C               18
#define A8_KEY_B               21
#define A8_KEY_X               22
#define A8_KEY_Z               23
#define A8_KEY_4               24
#define A8_KEY_3               26
#define A8_KEY_6               27
#define A8_KEY_ESCAPE               28
#define A8_KEY_5               29
#define A8_KEY_2               30
#define A8_KEY_PERIOD               34
#define A8_KEY_1               31
#define A8_KEY_COMMA               32
#define A8_KEY_SPACE               33
#define A8_KEY_N               35
#define A8_KEY_M               37
#define A8_KEY_SLASH               38
#define A8_KEY_FUJI               39
#define A8_KEY_R               40
#define A8_KEY_E               42
#define A8_KEY_Y               43
#define A8_KEY_TAB               44
#define A8_KEY_T               45
#define A8_KEY_W               46
#define A8_KEY_Q               47
#define A8_KEY_9               48
#define A8_KEY_0               50
#define A8_KEY_7               51
#define A8_KEY_DELETE               52
#define A8_KEY_8               53
#define A8_KEY_LESS_THAN               54
#define A8_KEY_GREATER_THAN               55
#define A8_KEY_F               56
#define A8_KEY_H               57
#define A8_KEY_D               58
#define A8_KEY_CAPS_LOWER               60
#define A8_KEY_G               61
#define A8_KEY_S               62
#define A8_KEY_A               63

#define A8_KEY_BREAK           15
#define A8_KEY_SHIFT           17
#define A8_KEY_CONTROL         18 

#define A8_KEY_INVALID         0xff

#endif
