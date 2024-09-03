#include <gb/gb.h>
#include <gb/drawing.h>
#include "primitives.h"

// Clears the screen
void clear(void) {
    UINT8 i, j;
    for (i = 0; i < 20; i++) { // GB screen is 20 columns wide and 18 columns tall
        for (j = 0; j < 18; j++) { 
            gotogxy(i, j);
            wrtchr(' '); // Use wrtchr to place a character when using the drawing library
        }
    }
}

/**
* Main function
**/

void main(void) {
    // Initialize transformation matrix
    fixed q;
    q.b.h = 0;
    q.b.l = 192;
    fixed z;
    z.b.h = 0;
    z.b.l = 0;
    Vec3f m1;
    setCoordsf(&m1, q, z, z);
    Vec3f m2;
    setCoordsf(&m2, z, q, z);
    Vec3f m3;
    setCoordsf(&m3, z, z, q);
    Mat3f m;
    setColumns(&m, m1, m2, m3);

    // Initialize Vec3s
    Vec3 v1;
    setCoords(&v1, 0, 0, 0);
    Vec3 v2;
    setCoords(&v2, 0, 40, 0);
    Vec3 v3;
    setCoords(&v3, 40, 0, 0);
    Vec3 v4;
    setCoords(&v4, 0, 40, 0);
    Vec3 v5;
    setCoords(&v5, 40, 0, 0);
    Vec3 v6;
    setCoords(&v6, 40, 40, 0);

    // Initialize Tris
    Tri t1;
    setVerts(&t1, v1, v2, v3);
    Tri t2;
    setVerts(&t2, v4, v5, v6);

    // Start the main loop
    while (1) {
        // Clear the screen
        clear();

        // Draw & transform the Tris
        drawTri(t1);
        drawTri(t2);
        transformTri(&t1, m);
        transformTri(&t2, m);

        // Delay ahead of next iter
        delay(1000);
    }
}