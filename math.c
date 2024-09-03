#include <gb/gb.h>
#include "math.h"

// Round a fixed to the nearest INT8
void round(INT8 *o, fixed x) {
    if (x.b.l < 128) {
        *o = (INT8)(x.b.h);
    } else {
        *o = (INT8)(x.b.h + 1);
    }
}

// Multiply an INT8 by a fixed
void multiply(INT8 *o, INT8 x, fixed y) {
    // Initialize a fixed from x
    fixed t;
    t.b.h = x;
    t.b.l = 0;

    // Multiply the fixed point numbers
    fixed p;
    p.w = t.w * y.w;

    // Shift the product back to get the result
    fixed r;
    r.w = p.w >> 8;

    // Round the result and return it
    round(o, r);
}