#include <stdlib.h>
#include <string.h>
#include <gb/gb.h>
#include <gb/drawing.h>
#include "math.h"
#include "linalg.h"
#include "quad.h"
#include "quadmesh.h"

// Copies a QuadMesh into another QuadMesh
void copyQuadMesh(QuadMesh *s, QuadMesh *d) {
    memcpy(d, s, sizeof(QuadMesh) + sizeof(Quad)*s->numQuads);
}

// Draws the QuadMesh to the screen
void drawQuadMesh(QuadMesh *m) {
    UINT8 i;
    color(BLACK, WHITE, SOLID);
    for (i = 0; i < m->numQuads; i++) {
        drawQuad(m->quads[i]);
    }
}

// Prints the QuadMesh to the screen
void printQuadMesh(QuadMesh *m) {
    UINT8 i;
    color(BLACK, WHITE, SOLID);
    for (i = 0; i < m->numQuads; i++) {
        printQuad(m->quads[i]);
    }
}

// Transforms the QuadMesh using a 3D transform
void transformQuadMesh(QuadMesh *m, Mat3 t) {
    UINT8 i;
    for (i = 0; i < m->numQuads; i++) {
        transformQuad(&(m->quads[i]), t);
    }
}

// Projects the QuadMesh
QuadMesh projectQuadMesh(QuadMesh m) {
    // Initialize a projected QuadMesh
    QuadMesh t;
    t.numQuads = m.numQuads;

    // Project each quad and add the projected quad to the mesh
    UINT8 i;
    for (i = 0; i < m.numQuads; i++) {
        Quad q;
        q = projectQuad(m.quads[i]);
        t.quads[i] = q;
    }

    // Return the projected QuadMesh
    return t;
}

// Clears the QuadMesh on the screen
void clearQuadMesh(QuadMesh *m) {
    UINT8 i;
    color(WHITE, WHITE, SOLID);
    for (i = 0; i < m->numQuads; i++) {
        drawQuad(m->quads[i]);
    }
}