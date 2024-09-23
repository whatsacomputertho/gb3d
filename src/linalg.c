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
INT32 transformX(Vec3 *v, Mat3 m) {
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
INT32 transformY(Vec3 *v, Mat3 m) {
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
INT32 transformZ(Vec3 *v, Mat3 m) {
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
void transformCoords(Vec3 *v, Mat3 m) {
    INT32 x;
    x = transformX(v, m);
    INT32 y;
    y = transformY(v, m);
    INT32 z;
    z = transformZ(v, m);
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

// Convert a Vec3 to a Vec4
Vec4 vec3tovec4(Vec3 *v) {
    Vec4 r;
    r.x = v->x;
    r.y = v->y;
    r.z = v->z;
    r.w = 1;
    return r;
}

// Convert a Vec4 to a Vec3
Vec3 vec4tovec3(Vec4 *v) {
    Vec3 r;
    r.x = v->x;
    r.y = v->y;
    r.z = v->z;
    return r;
}

// Get the projected x coordinate of a vec4
INT32 projectX(Vec4 *v, Mat4 m) {
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

// Get the projected y coordinate of a vec4
INT32 projectY(Vec4 *v, Mat4 m) {
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

// Get the projected z coordinate of a vec4
INT32 projectZ(Vec4 *v, Mat4 m) {
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

// Get the projected w coordinate of a vec4
INT32 projectW(Vec4 *v, Mat4 m) {
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

// Project the vertices of a vec4
void projectCoords(Vec4 *v) {
    // Initialize the perspective projection matrix
    Vec4 m1;
    setCoords4(&m1, P_NORM_1, 0, 0, 0);
    Vec4 m2;
    setCoords4(&m2, 0, P_NORM_1, 0, 0);
    Vec4 m3;
    setCoords4(&m3, 0, 0, P_NORM_2, P_NORM_3);
    Vec4 m4;
    setCoords4(&m4, 0, 0, 65536, 0);
    Mat4 m;
    setRows4(&m, m1, m2, m3, m4);

    // Transform the vertices using the matrix
    INT32 x;
    x = projectX(v, m);
    INT32 y;
    y = projectY(v, m);
    INT32 z;
    z = projectZ(v, m);
    INT32 w;
    w = projectW(v, m);

    // Update the coordinates of the vertices
    setCoords4(v, x, y, z, w);
}

// Initialize the rows of a mat4
void setRows4(Mat4 *m, Vec4 r1, Vec4 r2, Vec4 r3, Vec4 r4) {
    m->r1 = r1;
    m->r2 = r2;
    m->r3 = r3;
    m->r4 = r4;
}