#include <gb/gb.h>
#include <gb/drawing.h>
#include "primitives.h"
#include "mesh.h"
#include "frame.h"

/**
* Main function
**/

void main(void) {
    // Initialize transformation matrix
    INT16 q;
    q = 176; // cos pi/4 and sin pi/4
    Vec3f r1;
    setCoordsf(&r1, q, -q, 0);
    Vec3f r2;
    setCoordsf(&r2, q, q, 0);
    Vec3f r3;
    setCoordsf(&r3, 0, 0, 1);
    Mat3f m;
    setRows(&m, r1, r2, r3);

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
    Vec3 v7;
    setCoords(&v7, 0, 0, 40);
    Vec3 v8;
    setCoords(&v8, 0, 40, 40);
    Vec3 v9;
    setCoords(&v9, 40, 0, 40);
    Vec3 v10;
    setCoords(&v10, 0, 40, 40);
    Vec3 v11;
    setCoords(&v11, 40, 0, 40);
    Vec3 v12;
    setCoords(&v12, 40, 40, 40);

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