#include <stdlib.h>
#include <string.h>
#include <gb/gb.h>
#include <gb/drawing.h>
#include "math.h"
#include "linalg.h"
#include "tri.h"
#include "trimesh.h"

// Copies a TriMesh into another TriMesh
void copyTriMesh(TriMesh *s, TriMesh *d) {
    memcpy(d, s, sizeof(TriMesh) + sizeof(Tri)*s->numTris);
}

// Draws the TriMesh to the screen
void drawTriMesh(TriMesh *m) {
    UINT8 i;
    color(BLACK, WHITE, SOLID);
    for (i = 0; i < m->numTris; i++) {
        drawTri(m->tris[i]);
    }
}

// Prints the TriMesh to the screen
void printTriMesh(TriMesh *m) {
    UINT8 i;
    color(BLACK, WHITE, SOLID);
    for (i = 0; i < m->numTris; i++) {
        printTri(m->tris[i]);
    }
}

// Transforms the TriMesh using a 3D transform
void transformTriMesh(TriMesh *m, Mat3 t) {
    UINT8 i;
    for (i = 0; i < m->numTris; i++) {
        transformTri(&(m->tris[i]), t);
    }
}

// Projects the TriMesh
TriMesh projectTriMesh(TriMesh m) {
    // Initialize a projected TriMesh
    TriMesh t;
    t.numTris = m.numTris;

    // Project each tri and add the projected tri to the mesh
    UINT8 i;
    for (i = 0; i < m.numTris; i++) {
        Tri r;
        r = projectTri(&(m.tris[i]));
        t.tris[i] = r;
    }

    // Return the projected TriMesh
    return t;
}

// Clears the TriMesh on the screen
void clearTriMesh(TriMesh *m) {
    UINT8 i;
    color(WHITE, WHITE, SOLID);
    for (i = 0; i < m->numTris; i++) {
        drawTri(m->tris[i]);
    }
}