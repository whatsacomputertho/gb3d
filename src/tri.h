#ifndef TRI_H
#define TRI_H

// Define a Tri struct
typedef struct tri {
    Vec3 v1, v2, v3;
} Tri;

// Setter for Tri struct properties
void setVerts(Tri *t, Vec3 v1, Vec3 v2, Vec3 v3);

// Draws a Tri to the screen
void drawTri(Tri t);

// Prints a Tri to the screen
void printTri(Tri t);

// Transform Tri coordinates using a Mat3
void transformTri(Tri *t, Mat3 m);

#endif