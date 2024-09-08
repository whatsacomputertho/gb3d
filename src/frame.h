#ifndef FRAME_H
#define FRAME_H

#define MAX_MESHES 8

// A frame struct stores the meshes that are rendered
typedef struct frame {
    UINT8 activeFrame;
    UINT8 numMeshes;
    Mesh m1[MAX_MESHES];
    Mesh m2[MAX_MESHES];
} Frame;

// Set a mesh in the frame
void setMesh(Frame *f, UINT8 i, Mesh m);

// Update the frame, applying a transform in the process
void updateFrame(Frame *f, Mat3f t);

#endif