#include <gb/gb.h>
#include "math.h"

// Multiply two i16s
// Here the i16s are meant to represent a fixed-point decimal
// 0000 0000 . 0000 xxxx
INT16 _i16mul(INT16 x, INT16 y) {
    INT16 r;
    x = x >> 4;
    y = y >> 4;
    r = x * y;
    r = r >> 8;
    return r;
}

// Convert a i8 to a i16 ahead of multiplication
INT16 _i8toi16(INT8 x) {
    INT16 t;
    t = (INT16)x;
    t = t << 8;
    return t;
}

// Convert a i16 to a i8
INT8 i16toi8(INT16 x) {
    return (INT8)x;
}

// Convert an i8 to a u8
// Treated as a coordinate for drawing to the screen
UINT8 i8tou8(INT8 x) {
    return (UINT8)x + 87;
}

// Convert an i8 to a u8
// Treated as a coordinate for drawing to the screen
INT8 u8toi8(UINT8 x) {
    return (INT8)x;
}

// Multiply a i8 with a i16
// Here the i16 is meant to represent a fixed-point decimal
// 0000 0000 . 0000 xxxx
INT8 i8i16mul(INT8 x, INT16 y) {
    INT16 t;
    t = _i8toi16(x);
    INT16 r;
    r = _i16mul(y, t);
    return i16toi8(r);
}