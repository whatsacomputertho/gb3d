#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "math.h"
#include "linalg.h"
#include "tri.h"

// Initialize the vertices of a tri
void setTriVerts(Tri *t, Vec3 v1, Vec3 v2, Vec3 v3) {
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
    printf("v1: (%d, %d, %d)\n", i32tou8(t.v1.x, 0), i32tou8(t.v1.y, 0), i32tou8(t.v1.z, 0));
    printf("v2: (%d, %d, %d)\n", i32tou8(t.v2.x, 0), i32tou8(t.v2.y, 0), i32tou8(t.v2.z, 0));
    printf("v3: (%d, %d, %d)\n", i32tou8(t.v3.x, 0), i32tou8(t.v3.y, 0), i32tou8(t.v3.z, 0));
}

// Transform the vertices of a tri using a mat3
void transformTri(Tri *t, Mat3 m) {
    transformCoords(( Vec3* )t->v1, m);
    transformCoords(( Vec3* )t->v2, m);
    transformCoords(( Vec3* )t->v3, m);
}

// Transform the vertices of a tri using a mat4
Tri projectTri(Tri *t) {
    // Convert the tri vertices into vec4s
    Vec4 t1;
    t1 = vec3tovec4(( Vec3* )t->v1);
    Vec4 t2;
    t2 = vec3tovec4(( Vec3* )t->v2);
    Vec4 t3;
    t3 = vec3tovec4(( Vec3* )t->v3);

    // Project the vec4 converted tri vertices
    projectCoords(&t1);
    projectCoords(&t2);
    projectCoords(&t3);

    // Convert the projected tri vertices back to vec3s
    Tri r;
    r.v1 = vec4tovec3(&t1);
    r.v2 = vec4tovec3(&t2);
    r.v3 = vec4tovec3(&t3);

    // Normalize the projected tri vertices
    r.v1.x = i32div(r.v1.x, t1.w);
    r.v1.y = i32div(r.v1.y, t1.w);
    r.v1.z = i32div(r.v1.z, t1.w);
    r.v2.x = i32div(r.v2.x, t2.w);
    r.v2.y = i32div(r.v2.y, t2.w);
    r.v2.z = i32div(r.v2.z, t2.w);
    r.v3.x = i32div(r.v3.x, t3.w);
    r.v3.y = i32div(r.v3.y, t3.w);
    r.v3.z = i32div(r.v3.z, t3.w);

    // Return the projected tri
    return r;
}