#ifndef MESH_H
#define MESH_H

#define MAX_TRIS 32

// A mesh struct stores tris that are rendered
typedef struct mesh {
    UINT8 numTris;
    Tri tris[MAX_TRIS];
} Mesh;

// Copies a mesh into another mesh
void copyMesh(Mesh *s, Mesh *d);

// Draws the mesh to the screen
void drawMesh(Mesh *m);

// Prints the mesh to the screen
void printMesh(Mesh *m);

// Transforms the mesh
void transformMesh(Mesh *m, Mat3f t);

// Clears the mesh from the screen
void clearMesh(Mesh *m);

#endif