#include <gb/gb.h>
#include "primitives.h"
#include "mesh.h"
#include "frame.h"

// Set a mesh in the frame
void setMesh(Frame *f, UINT8 i, Mesh m) {\
    if (i >= f->numMeshes) {
        return ;
    }
    copyMesh(&m, &(f->m1[i]));
    copyMesh(&m, &(f->m2[i]));
}

// Update the frame, applying a transform in the process
void updateFrame(Frame *f, Mat3f t) {
    UINT8 i;
    if (f->activeFrame % 2 == 0) {
        for (i = 0; i < f->numMeshes; i++) {
            clearMesh(&(f->m2[i]));
            drawMesh(&(f->m1[i]));
            copyMesh(&(f->m1[i]), &(f->m2[i]));
            transformMesh(&(f->m2[i]), t);
        }
    } else {
        for (i = 0; i < f->numMeshes; i++) {
            clearMesh(&(f->m1[i]));
            drawMesh(&(f->m2[i]));
            copyMesh(&(f->m2[i]), &(f->m1[i]));
            transformMesh(&(f->m1[i]), t);
        }
    }
    f->activeFrame++;
}