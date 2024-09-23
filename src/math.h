#ifndef MATH_H
#define MATH_H

#define WIDTH_OFFSET 80
#define HEIGHT_OFFSET 72
#define DEPTH_OFFSET 76

// Multiply two i32s
// Here the i32s are meant to represent a fixed-point decimal
// 0000 0000 0000 0000 . 0000 0000 xxxx xxxx
INT32 i32mul(INT32 x, INT32 y);

// Divide two i32s
// Here the i32s are meant to represent a fixed-point decimal
// 0000 0000 0000 0000 . 0000 0000 xxxx xxxx
INT32 i32div(INT32 x, INT32 y);

// Convert a u8 to an i32 ahead of multiplication
INT32 u8toi32(UINT8 x);

// Convert an i32 to a u8
UINT8 i32tou8(INT32 x, UINT8 offset);

#endif