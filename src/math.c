#include <gb/gb.h>
#include "math.h"

// Round an i32 to the nearest integer
// Here the i32s are meant to represent a fixed-point decimal
// 0000 0000 0000 0000 . 0000 0000 xxxx xxxx
INT32 i32round(INT32 x) {
    UINT8 t;
    t = (UINT8)(x >> 8);
    INT32 m;
    m = (x & 65535);
    INT32 r;
    r = (x ^ m);
    if (t > 128) {
        return r + 1;
    }
    return r;
}

// Multiply two i32s
// Here the i32s are meant to represent a fixed-point decimal
// 0000 0000 0000 0000 . 0000 0000 xxxx xxxx
INT32 i32mul(INT32 x, INT32 y) {
    INT32 r;
    r = (x >> 8) * (y >> 8);
    r = i32round(r);
    return r;
}

// Convert a u8 to an i32 ahead of multiplication
INT32 u8toi32(UINT8 x) {
    INT32 t;
    t = (INT32)x;
    t = t << 16;
    return t;
}

// Convert an i32 to a u8
UINT8 i32tou8(INT32 x, UINT8 offset) {
    UINT8 t;
    t = ((UINT8)(x >> 16)) + offset;
    return t;
}