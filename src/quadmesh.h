#ifndef MESH_H
#define MESH_H

//#define MAX_QUADS 24
#define MAX_QUADS 6

// A QuadMesh struct stores tris that are rendered
typedef struct quadMesh {
    UINT8 numQuads;
    Quad quads[MAX_QUADS];
} QuadMesh;

// Copies a QuadMesh into another QuadMesh
void copyQuadMesh(QuadMesh *s, QuadMesh *d);

// Draws the QuadMesh to the screen
void drawQuadMesh(QuadMesh *m);

// Prints the QuadMesh to the screen
void printQuadMesh(QuadMesh *m);

// Transforms the QuadMesh using a 3D transform
void transformQuadMesh(QuadMesh *m, Mat3 t);

// Projects the QuadMesh
QuadMesh projectQuadMesh(QuadMesh m);

// Clears the QuadMesh from the screen
void clearQuadMesh(QuadMesh *m);

#endif