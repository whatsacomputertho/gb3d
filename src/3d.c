#include <gb/gb.h>
#include <gb/drawing.h>
#include "math.h"
#include "linalg.h"
#include "tri.h"
#include "mesh.h"
#include "frame.h"

/**
* Main function
**/

void main(void) {
    // Initialize transformation matrix
    INT32 q;
    q = 46336; // cos pi/4 and sin pi/4
    Vec3 r1;
    setCoords3(&r1, q, -q, 0);
    Vec3 r2;
    setCoords3(&r2, q, q, 0);
    Vec3 r3;
    setCoords3(&r3, 0, 0, 1);
    Mat3 m;
    setRows3(&m, r1, r2, r3);

    // Initialize Vec3s
    Vec3 v1;
    setCoords3(&v1, u8toi32(0), u8toi32(0), u8toi32(0));
    Vec3 v2;
    setCoords3(&v2, u8toi32(0), u8toi32(40), u8toi32(0));
    Vec3 v3;
    setCoords3(&v3, u8toi32(40), u8toi32(0), u8toi32(0));
    Vec3 v4;
    setCoords3(&v4, u8toi32(0), u8toi32(40), u8toi32(0));
    Vec3 v5;
    setCoords3(&v5, u8toi32(40), u8toi32(0), u8toi32(0));
    Vec3 v6;
    setCoords3(&v6, u8toi32(40), u8toi32(40), u8toi32(0));
    Vec3 v7;
    setCoords3(&v7, u8toi32(0), u8toi32(0), u8toi32(40));
    Vec3 v8;
    setCoords3(&v8, u8toi32(0), u8toi32(40), u8toi32(40));
    Vec3 v9;
    setCoords3(&v9, u8toi32(40), u8toi32(0), u8toi32(40));
    Vec3 v10;
    setCoords3(&v10, u8toi32(0), u8toi32(40), u8toi32(40));
    Vec3 v11;
    setCoords3(&v11, u8toi32(40), u8toi32(0), u8toi32(40));
    Vec3 v12;
    setCoords3(&v12, u8toi32(40), u8toi32(40), u8toi32(40));

    // Initialize Tris
    Tri t1;
    setVerts(&t1, v1, v2, v3);
    Tri t2;
    setVerts(&t2, v4, v5, v6);
    Tri t3;
    setVerts(&t3, v7, v8, v9);
    Tri t4;
    setVerts(&t4, v10, v11, v12);

    // Initialize mesh
    Mesh m1;
    m1.numTris = 4;
    m1.tris[0] = t1;
    m1.tris[1] = t2;
    m1.tris[2] = t3;
    m1.tris[3] = t4;

    // Initialize frame
    Frame f1;
    f1.numMeshes = 1;
    f1.activeFrame = 0;
    setMesh(&f1, 0, m1);

    // Start the main loop
    UINT8 i = 0;
    while (1) {
        updateFrame(&f1, m);
        delay(10);
    }
}