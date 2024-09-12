#include <gb/gb.h>
#include "math.h"
#include "linalg.h"

// Setter for Vec3 struct properties
void setCoords3(Vec3 *v, INT32 x, INT32 y, INT32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

// Get the transformed x coordinate of a vec3 using a mat3
INT32 transformX3(Vec3 *v, Mat3 m) {
    INT32 x1;
    x1 = i32mul(v->x, m.r1.x);
    INT32 x2;
    x2 = i32mul(v->y, m.r1.y);
    INT32 x3;
    x3 = i32mul(v->z, m.r1.z);
    INT32 x = x1 + x2 + x3;
    return x;
}

// Get the transformed y coordinate of a vec3 using a mat3
INT32 transformY3(Vec3 *v, Mat3 m) {
    INT32 y1;
    y1 = i32mul(v->x, m.r2.x);
    INT32 y2;
    y2 = i32mul(v->y, m.r2.y);
    INT32 y3;
    y3 = i32mul(v->z, m.r2.z);
    INT32 y = y1 + y2 + y3;
    return y;
}

// Get the transformed z coordinate of a vec3 using a mat3
INT32 transformZ3(Vec3 *v, Mat3 m) {
    INT32 z1;
    z1 = i32mul(v->x, m.r3.x);
    INT32 z2;
    z2 = i32mul(v->y, m.r3.y);
    INT32 z3;
    z3 = i32mul(v->z, m.r3.z);
    INT32 z = z1 + z2 + z3;
    return z;
}

// Transform the vertices of a vec3 using a mat3
void transformCoords3(Vec3 *v, Mat3 m) {
    INT32 x;
    x = transformX3(v, m);
    INT32 y;
    y = transformY3(v, m);
    INT32 z;
    z = transformZ3(v, m);
    setCoords3(v, x, y, z);
}

// Initialize the rows of a mat3
void setRows3(Mat3 *m, Vec3 r1, Vec3 r2, Vec3 r3) {
    m->r1 = r1;
    m->r2 = r2;
    m->r3 = r3;
}

// Setter for Vec4 struct properties
void setCoords4(Vec4 *v, INT32 x, INT32 y, INT32 z, INT32 w) {
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

// Get the transformed x coordinate of a vec4 using a mat4
INT32 transformX4(Vec4 *v, Mat4 m) {
    INT32 x1;
    x1 = i32mul(v->x, m.r1.x);
    INT32 x2;
    x2 = i32mul(v->y, m.r1.y);
    INT32 x3;
    x3 = i32mul(v->z, m.r1.z);
    INT32 x4;
    x4 = i32mul(v->w, m.r1.w);
    INT32 x = x1 + x2 + x3 + x4;
    return x;
}

// Get the transformed y coordinate of a vec4 using a mat4
INT32 transformY4(Vec4 *v, Mat4 m) {
    INT32 y1;
    y1 = i32mul(v->x, m.r2.x);
    INT32 y2;
    y2 = i32mul(v->y, m.r2.y);
    INT32 y3;
    y3 = i32mul(v->z, m.r2.z);
    INT32 y4;
    y4 = i32mul(v->w, m.r2.w);
    INT32 y = y1 + y2 + y3 + y4;
    return y;
}

// Get the transformed z coordinate of a vec4 using a mat4
INT32 transformZ4(Vec4 *v, Mat4 m) {
    INT32 z1;
    z1 = i32mul(v->x, m.r3.x);
    INT32 z2;
    z2 = i32mul(v->y, m.r3.y);
    INT32 z3;
    z3 = i32mul(v->z, m.r3.z);
    INT32 z4;
    z4 = i32mul(v->w, m.r3.w);
    INT32 z = z1 + z2 + z3 + z4;
    return z;
}

// Get the transformed w coordinate of a vec4 using a mat4
INT32 transformW4(Vec4 *v, Mat4 m) {
    INT32 w1;
    w1 = i32mul(v->x, m.r4.x);
    INT32 w2;
    w2 = i32mul(v->y, m.r4.y);
    INT32 w3;
    w3 = i32mul(v->z, m.r4.z);
    INT32 w4;
    w4 = i32mul(v->w, m.r4.w);
    INT32 w = w1 + w2 + w3 + w4;
    return w;
}

// Transform the vertices of a vec4 using a mat4
void transformCoords4(Vec4 *v, Mat4 m) {
    INT32 x;
    x = transformX4(v, m);
    INT32 y;
    y = transformY4(v, m);
    INT32 z;
    z = transformZ4(v, m);
    INT32 w;
    w = transformW4(v, m);
    setCoords4(v, x, y, z, w);
}

// Initialize the rows of a mat4
void setRows4(Mat4 *m, Vec4 r1, Vec4 r2, Vec4 r3, Vec4 r4) {
    m->r1 = r1;
    m->r2 = r2;
    m->r3 = r3;
    m->r4 = r4;
}