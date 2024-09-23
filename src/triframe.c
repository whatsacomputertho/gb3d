#include <gb/gb.h>
#include "linalg.h"
#include "tri.h"
#include "trimesh.h"
#include "triframe.h"

// Set a TriMesh in the frame
void setTriMesh(TriFrame *f, UINT8 i, TriMesh m) {
    if (i >= f->numMeshes) {
        return ;
    }
    copyTriMesh(&m, &(f->m1[i]));
    copyTriMesh(&m, &(f->m2[i]));
}

// Transform the TriFrame by applying a 3D transform
void transformTriFrame(TriFrame *f, Mat3 t) {
    UINT8 i;
    for (i = 0; i < f->numMeshes; i++) {
        transformTriMesh(&(f->m1[i]), t);
    }
}

// Draw the TriFrame to the screen, projecting it in the process
void drawTriFrame(TriFrame *f) {
    UINT8 i;
    for (i = 0; i < f->numMeshes; i++) {
        clearTriMesh(&(f->m2[i]));
        f->m2[i] = projectTriMesh(f->m1[i]);
        drawTriMesh(&(f->m2[i]));
    }
}