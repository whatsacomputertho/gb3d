#include <gb/gb.h>
#include <gb/drawing.h>
#include "math.h"
#include "linalg.h"
#include "quad.h"
#include "quadmesh.h"
#include "quadframe.h"

/**
* Main function
**/

void main(void) {
    // Initialize transformation matrix
    INT32 rot;
    rot = 46336; // cos pi/4 and sin pi/4
    Vec3 r1;
    setCoords3(&r1, rot, -rot, 0);
    Vec3 r2;
    setCoords3(&r2, rot, rot, 0);
    Vec3 r3;
    setCoords3(&r3, 0, 0, 65536);
    Mat3 m;
    setRows3(&m, r1, r2, r3);

    // Initialize Vec3s - front cube face
    Vec3 v1;
    setCoords3(&v1, u8toi32(0), u8toi32(0), u8toi32(1));
    Vec3 v2;
    setCoords3(&v2, u8toi32(0), u8toi32(4), u8toi32(1));
    Vec3 v3;
    setCoords3(&v3, u8toi32(4), u8toi32(4), u8toi32(1));
    Vec3 v4;
    setCoords3(&v4, u8toi32(4), u8toi32(0), u8toi32(1));

    // Initialize Vec3s - back cube face
    Vec3 v5;
    setCoords3(&v5, u8toi32(0), u8toi32(0), u8toi32(5));
    Vec3 v6;
    setCoords3(&v6, u8toi32(0), u8toi32(4), u8toi32(5));
    Vec3 v7;
    setCoords3(&v7, u8toi32(4), u8toi32(4), u8toi32(5));
    Vec3 v8;
    setCoords3(&v8, u8toi32(4), u8toi32(0), u8toi32(5));

    // Initialize Vec3s - right cube face
    Vec3 v9;
    setCoords3(&v9, u8toi32(4), u8toi32(0), u8toi32(1));
    Vec3 v10;
    setCoords3(&v10, u8toi32(4), u8toi32(4), u8toi32(1));
    Vec3 v11;
    setCoords3(&v11, u8toi32(4), u8toi32(4), u8toi32(5));
    Vec3 v12;
    setCoords3(&v12, u8toi32(4), u8toi32(0), u8toi32(5));

    // Initialize Vec3s - bottom cube face
    Vec3 v13;
    setCoords3(&v13, u8toi32(0), u8toi32(4), u8toi32(1));
    Vec3 v14;
    setCoords3(&v14, u8toi32(4), u8toi32(4), u8toi32(1));
    Vec3 v15;
    setCoords3(&v15, u8toi32(4), u8toi32(4), u8toi32(5));
    Vec3 v16;
    setCoords3(&v16, u8toi32(0), u8toi32(4), u8toi32(5));

    // Initialize Quads
    Quad q1;
    setQuadVerts(&q1, v1, v2, v3, v4);
    Quad q2;
    setQuadVerts(&q2, v5, v6, v7, v8);
    Quad q3;
    setQuadVerts(&q3, v9, v10, v11, v12);
    Quad q4;
    setQuadVerts(&q4, v13, v14, v15, v16);

    // Initialize QuadMesh
    QuadMesh q;
    q.numQuads = 4;
    q.quads[0] = q1;
    q.quads[1] = q2;
    q.quads[2] = q3;
    q.quads[3] = q4;

    // Initialize QuadFrame
    QuadFrame f;
    f.numMeshes = 1;
    setQuadMesh(&f, 0, q);

    // Start the main loop
    while (1) {
        drawQuadFrame(&f);
        transformQuadFrame(&f, m);
        delay(1000);
    }
}