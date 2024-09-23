#ifndef TRIMESH_H
#define TRIMESH_H

#define MAX_TRIS 32

// A TriMesh struct stores tris that are rendered
typedef struct triMesh {
    UINT8 numTris;
    Tri tris[MAX_TRIS];
} TriMesh;

// Copies a TriMesh into another TriMesh
void copyTriMesh(TriMesh *s, TriMesh *d);

// Draws the TriMesh to the screen
void drawTriMesh(TriMesh *m);

// Prints the TriMesh to the screen
void printTriMesh(TriMesh *m);

// Transforms the TriMesh using a 3D transform
void transformTriMesh(TriMesh *m, Mat3 t);

// Projects the TriMesh
TriMesh projectTriMesh(TriMesh m);

// Clears the TriMesh from the screen
void clearTriMesh(TriMesh *m);

#endif