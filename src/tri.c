#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "math.h"
#include "linalg.h"
#include "tri.h"

// Initialize the vertices of a tri
void setVerts(Tri *t, Vec3 v1, Vec3 v2, Vec3 v3) {
    t->v1 = v1;
    t->v2 = v2;
    t->v3 = v3;
}

// Draw a tri
void drawTri(Tri t) {
    line(i32tou8(t.v1.x, WIDTH_OFFSET), i32tou8(t.v1.y, HEIGHT_OFFSET), i32tou8(t.v2.x, WIDTH_OFFSET), i32tou8(t.v2.y, HEIGHT_OFFSET));
    line(i32tou8(t.v2.x, WIDTH_OFFSET), i32tou8(t.v2.y, HEIGHT_OFFSET), i32tou8(t.v3.x, WIDTH_OFFSET), i32tou8(t.v3.y, HEIGHT_OFFSET));
    line(i32tou8(t.v3.x, WIDTH_OFFSET), i32tou8(t.v3.y, HEIGHT_OFFSET), i32tou8(t.v1.x, WIDTH_OFFSET), i32tou8(t.v1.y, HEIGHT_OFFSET));
}

// Print a tri
void printTri(Tri t) {
    printf("Tri\n");
    printf("v1: (%d, %d, %d)\n", i32tou8(t.v1.x, WIDTH_OFFSET), i32tou8(t.v1.y, HEIGHT_OFFSET), i32tou8(t.v1.z, DEPTH_OFFSET));
    printf("v2: (%d, %d, %d)\n", i32tou8(t.v2.x, WIDTH_OFFSET), i32tou8(t.v2.y, HEIGHT_OFFSET), i32tou8(t.v2.z, DEPTH_OFFSET));
    printf("v3: (%d, %d, %d)\n", i32tou8(t.v3.x, WIDTH_OFFSET), i32tou8(t.v3.y, HEIGHT_OFFSET), i32tou8(t.v3.z, DEPTH_OFFSET));
}

// Transform the vertices of a tri using a mat3
void transformTri(Tri *t, Mat3 m) {
    transformCoords3(( Vec3* )t->v1, m);
    transformCoords3(( Vec3* )t->v2, m);
    transformCoords3(( Vec3* )t->v3, m);
}