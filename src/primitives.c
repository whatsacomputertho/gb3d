#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "primitives.h"
#include "math.h"

// Initialize the values of a vec3
void setCoords(Vec3 *v, UINT8 x, UINT8 y, UINT8 z) {
    v->x = u8toi8(x);
    v->y = u8toi8(y);
    v->z = u8toi8(z);
}

// Initialize the vertices of a tri
void setVerts(Tri *t, Vec3 v1, Vec3 v2, Vec3 v3) {
    t->v1 = v1;
    t->v2 = v2;
    t->v3 = v3;
}

// Draw a tri
void drawTri(Tri t) {
    line(i8tou8(t.v1.x), i8tou8(t.v1.y), i8tou8(t.v2.x), i8tou8(t.v2.y));
    line(i8tou8(t.v2.x), i8tou8(t.v2.y), i8tou8(t.v3.x), i8tou8(t.v3.y));
    line(i8tou8(t.v3.x), i8tou8(t.v3.y), i8tou8(t.v1.x), i8tou8(t.v1.y));
}

// Print a tri
void printTri(Tri t) {
    printf("Tri\n");
    printf("v1: (%d, %d, %d)\n", i8tou8(t.v1.x), i8tou8(t.v1.y), i8tou8(t.v1.z));
    printf("v2: (%d, %d, %d)\n", i8tou8(t.v2.x), i8tou8(t.v2.y), i8tou8(t.v2.z));
    printf("v3: (%d, %d, %d)\n", i8tou8(t.v3.x), i8tou8(t.v3.y), i8tou8(t.v3.z));
}

// Initialize the values of a vec3f
void setCoordsf(Vec3f *v, INT16 x, INT16 y, INT16 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// Initialize the columns of a mat3f
void setRows(Mat3f *m, Vec3f r1, Vec3f r2, Vec3f r3) {
    m->r1 = r1;
    m->r2 = r2;
    m->r3 = r3;
}

// Get the transformed x coordinate of a vec3 using a mat3f
INT8 transformX(Vec3 *v, Mat3f m) {
    INT8 x1;
    x1 = i8i16mul(v->x, m.r1.x);
    INT8 x2;
    x2 = i8i16mul(v->y, m.r1.y);
    INT8 x3;
    x3 = i8i16mul(v->z, m.r1.z);
    INT8 x = x1 + x2 + x3;
    return x;
}

// Get the transformed y coordinate of a vec3 using a mat3f
INT8 transformY(Vec3 *v, Mat3f m) {
    INT8 y1;
    y1 = i8i16mul(v->x, m.r2.x);
    INT8 y2;
    y2 = i8i16mul(v->y, m.r2.y);
    INT8 y3;
    y3 = i8i16mul(v->z, m.r2.z);
    INT8 y = y1 + y2 + y3;
    return y;
}

// Get the transformed z coordinate of a vec3 using a mat3f
INT8 transformZ(Vec3 *v, Mat3f m) {
    INT8 z1;
    z1 = i8i16mul(v->x, m.r3.x);
    INT8 z2;
    z2 = i8i16mul(v->y, m.r3.y);
    INT8 z3;
    z3 = i8i16mul(v->z, m.r3.z);
    INT8 z = z1 + z2 + z3;
    return z;
}

// Transform the vertices of a vec3 using a mat3f
void transformCoords(Vec3 *v, Mat3f m) {
    INT8 x;
    x = transformX(v, m);
    INT8 y;
    y = transformY(v, m);
    INT8 z;
    z = transformZ(v, m);
    setCoords(v, x, y, z);
}

// Transform the vertices of a tri using a mat3f
void transformTri(Tri *t, Mat3f m) {
    transformCoords(( Vec3* )t->v1, m);
    transformCoords(( Vec3* )t->v2, m);
    transformCoords(( Vec3* )t->v3, m);
}