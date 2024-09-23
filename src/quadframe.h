#ifndef FRAME_H
#define FRAME_H

#define MAX_MESHES 1

// A QuadFrame struct stores the QuadMeshes that are rendered
typedef struct quadFrame {
    UINT8 numMeshes;
    QuadMesh m1[MAX_MESHES];
    QuadMesh m2[MAX_MESHES];
} QuadFrame;

// Set a QuadMesh in the QuadFrame
void setQuadMesh(QuadFrame *f, UINT8 i, QuadMesh m);

// Transform all the meshes in the TriFrame
void transformQuadFrame(QuadFrame *f, Mat3 t);

// Draw the QuadFrame to the screen
void drawQuadFrame(QuadFrame *f);

#endif