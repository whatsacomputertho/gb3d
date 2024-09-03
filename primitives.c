#include <gb/gb.h>
#include <gb/drawing.h>
#include "primitives.h"
#include "math.h"

// Initialize the values of a vec3
void setCoords(Vec3 *v, INT8 x, INT8 y, INT8 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// Initialize the vertices of a tri
void setVerts(Tri *t, Vec3 v1, Vec3 v2, Vec3 v3) {
    t->v1 = v1;
    t->v2 = v2;
    t->v3 = v3;
}

// Draw a tri
void drawTri(Tri t) {
    line(t.v1.x, t.v1.y, t.v2.x, t.v2.y);
    line(t.v2.x, t.v2.y, t.v3.x, t.v3.y);
    line(t.v3.x, t.v3.y, t.v1.x, t.v1.y);
}

// Initialize the values of a vec3f
void setCoordsf(Vec3f *v, fixed x, fixed y, fixed z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// Initialize the columns of a mat3f
void setColumns(Mat3f *m, Vec3f v1, Vec3f v2, Vec3f v3) {
    m->c1 = v1;
    m->c2 = v2;
    m->c3 = v3;
}

// Get the transformed x coordinate of a vec3 using a mat3f
void transformX(INT8 *o, Vec3 *v, Mat3f m) {
    INT8 x1;
    multiply(&x1, v->x, m.c1.x);
    INT8 x2;
    multiply(&x2, v->y, m.c2.x);
    INT8 x3;
    multiply(&x3, v->z, m.c3.x);
    INT8 x = x1 + x2 + x3;
    *o = x;
}

// Get the transformed y coordinate of a vec3 using a mat3f
void transformY(INT8 *o, Vec3 *v, Mat3f m) {
    INT8 y1;
    multiply(&y1, v->x, m.c1.y);
    INT8 y2;
    multiply(&y2, v->y, m.c2.y);
    INT8 y3;
    multiply(&y3, v->z, m.c3.y);
    INT8 y = y1 + y2 + y3;
    *o = y;
}

// Get the transformed z coordinate of a vec3 using a mat3f
void transformZ(INT8 *o, Vec3 *v, Mat3f m) {
    INT8 z1;
    multiply(&z1, v->x, m.c1.z);
    INT8 z2;
    multiply(&z2, v->y, m.c2.z);
    INT8 z3;
    multiply(&z3, v->z, m.c3.z);
    INT8 z = z1 + z2 + z3;
    *o = z;
}

// Transform the vertices of a vec3 using a mat3f
void transformCoords(Vec3 *v, Mat3f m) {
    INT8 x;
    transformX(&x, v, m);
    INT8 y;
    transformY(&y, v, m);
    INT8 z;
    transformZ(&z, v, m);
    setCoords(v, x, y, z);
}

// Transform the vertices of a tri using a mat3f
void transformTri(Tri *t, Mat3f m) {
    transformCoords(( Vec3* )t->v1, m);
    transformCoords(( Vec3* )t->v2, m);
    transformCoords(( Vec3* )t->v3, m);
}