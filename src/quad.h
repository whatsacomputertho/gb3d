#ifndef QUAD_H
#define QUAD_H

// Define a Quad struct
typedef struct quad {
    Vec3 v1, v2, v3, v4;
} Quad;

// Setter for Quad struct properties
void setQuadVerts(Quad *q, Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4);

// Draws a Quad to the screen
void drawQuad(Quad q);

// Prints a Quad to the screen
void printQuad(Quad q);

// Transform Quad coordinates using a Mat3
void transformQuad(Quad *q, Mat3 m);

// Transform Quad coordinates using a Mat4
Quad projectQuad(Quad q);

#endif