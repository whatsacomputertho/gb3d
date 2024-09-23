#include <gb/gb.h>
#include "linalg.h"
#include "quad.h"
#include "quadmesh.h"
#include "quadframe.h"

// Set a QuadMesh in the frame
void setQuadMesh(QuadFrame *f, UINT8 i, QuadMesh m) {
    if (i >= f->numMeshes) {
        return ;
    }
    copyQuadMesh(&m, &(f->m1[i]));
}

// Transform the QuadFrame by applying a 3D transform
void transformQuadFrame(QuadFrame *f, Mat3 t) {
    UINT8 i;
    for (i = 0; i < f->numMeshes; i++) {
        transformQuadMesh(&(f->m1[i]), t);
    }
}

// Draw the QuadFrame to the screen, projecting it in the process
void drawQuadFrame(QuadFrame *f) {
    UINT8 i;
    for (i = 0; i < f->numMeshes; i++) {
        clearQuadMesh(&(f->m2[i]));
        f->m2[i] = projectQuadMesh(f->m1[i]);
        drawQuadMesh(&(f->m2[i]));
        //printQuadMesh(&(f->m2[i]));
    }
}