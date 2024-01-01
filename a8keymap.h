#ifndef _A8KEYMAP_H
#define _A8KEYMAP_H

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
#define A8_KEY_PERIOD               31
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

#define A8_KEY_BREAK           64
#define A8_KEY_SHIFT           65
#define A8_KEY_CONTROL         66 // TODO FIGURE OUT THESE

#define A8_KEY_INVALID         0xff


uint8_t a8keymap[128] = {A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_A,
                         A8_KEY_B,
                         A8_KEY_C,
                         A8_KEY_D,
                         A8_KEY_E,
                         A8_KEY_F,
                         A8_KEY_G,
                         A8_KEY_H,
                         A8_KEY_I,
                         A8_KEY_J,
                         A8_KEY_K,
                         A8_KEY_L,
                         A8_KEY_M,
                         A8_KEY_N,
                         A8_KEY_O,
                         A8_KEY_P,
                         A8_KEY_Q,
                         A8_KEY_R,
                         A8_KEY_S,
                         A8_KEY_T,
                         A8_KEY_U,
                         A8_KEY_V,
                         A8_KEY_W,
                         A8_KEY_X,
                         A8_KEY_Y,
                         A8_KEY_Z,
                         A8_KEY_1,
                         A8_KEY_2,
                         A8_KEY_3,
                         A8_KEY_4,
                         A8_KEY_5,
                         A8_KEY_6,
                         A8_KEY_7,
                         A8_KEY_8,
                         A8_KEY_9,
                         A8_KEY_0,
                         A8_KEY_RETURN,
                         A8_KEY_ESCAPE,
                         A8_KEY_DELETE,
                         A8_KEY_TAB,
                         A8_KEY_SPACE,
                         A8_KEY_MINUS,
                         A8_KEY_EQUAL,
                         A8_KEY_COMMA,
                         A8_KEY_PERIOD,
                         A8_KEY_PLUS,
                         A8_KEY_INVALID,
                         A8_KEY_SEMICOLON,
                         A8_KEY_7,
                         A8_KEY_INVALID,
                         A8_KEY_COMMA,
                         A8_KEY_PERIOD,
                         A8_KEY_SLASH,
                         A8_KEY_CAPS_LOWER,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_BREAK,
                         A8_KEY_GREATER_THAN,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_DELETE,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_ASTERISK,
                         A8_KEY_PLUS,
                         A8_KEY_EQUAL,
                         A8_KEY_MINUS,
                         A8_KEY_INVALID,
                         A8_KEY_SLASH,
                         A8_KEY_ASTERISK,
                         A8_KEY_MINUS,
                         A8_KEY_PLUS,
                         A8_KEY_RETURN,
                         A8_KEY_1,
                         A8_KEY_2,
                         A8_KEY_3,
                         A8_KEY_4,
                         A8_KEY_5,
                         A8_KEY_6,
                         A8_KEY_7,
                         A8_KEY_8,
                         A8_KEY_9,
                         A8_KEY_0,
                         A8_KEY_PERIOD,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_EQUAL,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID,
                         A8_KEY_INVALID}

#endif
