#ifndef FRAME_H
#define FRAME_H

#define MAX_MESHES 1

// A TriFrame struct stores the TriMeshes that are rendered
typedef struct triFrame {
    UINT8 numMeshes;
    TriMesh m1[MAX_MESHES];
    TriMesh m2[MAX_MESHES];
} TriFrame;

// Set a TriMesh in the TriFrame
void setTriMesh(TriFrame *f, UINT8 i, TriMesh m);

// Transform all the meshes in the TriFrame
void transformTriFrame(TriFrame *f, Mat3 t);

// Draw the TriFrame to the screen
void drawTriFrame(TriFrame *f);

#endif