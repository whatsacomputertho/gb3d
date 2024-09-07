#ifndef MATH_H
#define MATH_H

// Multiply two i16s
// Here the i16s are meant to represent a fixed-point decimal
// 0000 0000 . 0000 xxxx
INT16 _i16mul(INT16 x, INT16 y);

// Convert a i8 to a i16 ahead of multiplication
INT16 _i8toi16(INT8 x);

// Convert a i16 to a i8
INT8 i16toi8(INT16 x);

// Convert an i8 to a u8
// Treated as a coordinate for drawing to the screen
UINT8 i8tou8(INT8 x);

// Convert a u8 to an i8
// Treated as the underlying value on which math is done
INT8 u8toi8(UINT8 x);

// Multiply a i8 with a i16
// Here the i16 is meant to represent a fixed-point decimal
// 0000 0000 . 0000 xxxx
INT8 i8i16mul(INT8 x, INT16 y);

#endif