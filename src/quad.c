#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>
#include "math.h"
#include "linalg.h"
#include "quad.h"

// Initialize the vertices of a quad
void setQuadVerts(Quad *q, Vec3 v1, Vec3 v2, Vec3 v3, Vec3 v4) {
    q->v1 = v1;
    q->v2 = v2;
    q->v3 = v3;
    q->v4 = v4;
}

// Draw a quad
void drawQuad(Quad q) {
    line(i32tou8(q.v1.x, WIDTH_OFFSET), i32tou8(q.v1.y, HEIGHT_OFFSET), i32tou8(q.v2.x, WIDTH_OFFSET), i32tou8(q.v2.y, HEIGHT_OFFSET));
    line(i32tou8(q.v2.x, WIDTH_OFFSET), i32tou8(q.v2.y, HEIGHT_OFFSET), i32tou8(q.v3.x, WIDTH_OFFSET), i32tou8(q.v3.y, HEIGHT_OFFSET));
    line(i32tou8(q.v3.x, WIDTH_OFFSET), i32tou8(q.v3.y, HEIGHT_OFFSET), i32tou8(q.v4.x, WIDTH_OFFSET), i32tou8(q.v4.y, HEIGHT_OFFSET));
    line(i32tou8(q.v4.x, WIDTH_OFFSET), i32tou8(q.v4.y, HEIGHT_OFFSET), i32tou8(q.v1.x, WIDTH_OFFSET), i32tou8(q.v1.y, HEIGHT_OFFSET));
}

// Print a quad
void printQuad(Quad q) {
    printf("Quad\n");
    printf("v1: (%d, %d, %d)\n", i32tou8(q.v1.x, 0), i32tou8(q.v1.y, 0), i32tou8(q.v1.z, 0));
    printf("v2: (%d, %d, %d)\n", i32tou8(q.v2.x, 0), i32tou8(q.v2.y, 0), i32tou8(q.v2.z, 0));
    printf("v3: (%d, %d, %d)\n", i32tou8(q.v3.x, 0), i32tou8(q.v3.y, 0), i32tou8(q.v3.z, 0));
    printf("v4: (%d, %d, %d)\n", i32tou8(q.v4.x, 0), i32tou8(q.v4.y, 0), i32tou8(q.v4.z, 0));
}

// Transform the vertices of a quad using a mat3
void transformQuad(Quad *q, Mat3 m) {
    transformCoords(( Vec3* )q->v1, m);
    transformCoords(( Vec3* )q->v2, m);
    transformCoords(( Vec3* )q->v3, m);
    transformCoords(( Vec3* )q->v4, m);
}

// Project the vertices of a quad into another quad
Quad projectQuad(Quad q) {
    // Convert the quad vertices into vec4s
    Vec4 t1;
    t1 = vec3tovec4(&(q.v1));
    Vec4 t2;
    t2 = vec3tovec4(&(q.v2));
    Vec4 t3;
    t3 = vec3tovec4(&(q.v3));
    Vec4 t4;
    t4 = vec3tovec4(&(q.v4));

    // Project the vec4 converted quad vertices
    projectCoords(&t1);
    projectCoords(&t2);
    projectCoords(&t3);
    projectCoords(&t4);

    // Convert the projected quad vertices back to vec3s
    Quad t;
    t.v1 = vec4tovec3(&t1);
    t.v2 = vec4tovec3(&t2);
    t.v3 = vec4tovec3(&t3);
    t.v4 = vec4tovec3(&t4);

    // Normalize the projected quad vertices
    t.v1.x = i32div(t.v1.x, t1.w);
    t.v1.y = i32div(t.v1.y, t1.w);
    t.v1.z = i32div(t.v1.z, t1.w);
    t.v2.x = i32div(t.v2.x, t2.w);
    t.v2.y = i32div(t.v2.y, t2.w);
    t.v2.z = i32div(t.v2.z, t2.w);
    t.v3.x = i32div(t.v3.x, t3.w);
    t.v3.y = i32div(t.v3.y, t3.w);
    t.v3.z = i32div(t.v3.z, t3.w);
    t.v4.x = i32div(t.v4.x, t4.w);
    t.v4.y = i32div(t.v4.y, t4.w);
    t.v4.z = i32div(t.v4.z, t4.w);

    // Return the projected quad
    return t;
}