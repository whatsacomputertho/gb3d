#include <stdlib.h>
#include <string.h>
#include <gb/gb.h>
#include <gb/drawing.h>
#include "math.h"
#include "linalg.h"
#include "tri.h"
#include "mesh.h"

// Copies a mesh into another mesh
void copyMesh(Mesh *s, Mesh *d) {
    memcpy(d, s, sizeof(Tri)*s->numTris);
}

// Draws the mesh to the screen
void drawMesh(Mesh *m) {
    UINT8 i;
    color(BLACK, WHITE, SOLID);
    for (i = 0; i < m->numTris; i++) {
        drawTri(m->tris[i]);
    }
}

// Prints the mesh to the screen
void printMesh(Mesh *m) {
    UINT8 i;
    color(BLACK, WHITE, SOLID);
    for (i = 0; i < m->numTris; i++) {
        printTri(m->tris[i]);
    }
}

// Transforms the mesh
void transformMesh(Mesh *m, Mat3 t) {
    UINT8 i;
    for (i = 0; i < m->numTris; i++) {
        transformTri(&(m->tris[i]), t);
    }
}

// Clears the frame on the screen
void clearMesh(Mesh *m) {
    UINT8 i;
    color(WHITE, WHITE, SOLID);
    for (i = 0; i < m->numTris; i++) {
        drawTri(m->tris[i]);
    }
}