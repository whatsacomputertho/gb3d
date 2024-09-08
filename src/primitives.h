#ifndef PRIMITIVES_H
#define PRIMITIVES_H

// Define a Vec3 struct
typedef struct vec3 {
	INT8 x, y, z;
} Vec3;

// Setter for Vec3 struct properties
void setCoords(Vec3 *v, UINT8 x, UINT8 y, UINT8 z);

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

// Define a Vec3f struct
typedef struct vec3f {
    INT16 x, y, z;
} Vec3f;

// Setter for Vec3f struct properties
void setCoordsf(Vec3f *v, INT16 x, INT16 y, INT16 z);

// Define a Mat3f struct
typedef struct mat3f {
    Vec3f r1, r2, r3;
} Mat3f;

// Setter for Mat3f struct properties
void setRows(Mat3f *m, Vec3f r1, Vec3f r2, Vec3f r3);

// Transform Vec3 coordinates using a Mat3f
void transformCoords(Vec3 *v, Mat3f m);

// Transform Tri coordinates using a Mat3f
void transformTri(Tri *t, Mat3f m);

// Define a Vec4 struct
typedef struct vec4 {
    INT8 x, y, z, w;
} Vec4;

// Setter for Vec4 struct properties
void setCoords4(Vec4 *v, UINT8 x, UINT8 y, UINT8 z, UINT8 w);

// Define a Vec4f struct
typedef struct vec4f {
    INT16 x, y, z, w;
} Vec4f;

// Setter for Vec4f struct properties
void setCoords4f(Vec4f *v, INT16 x, INT16 y, INT16 z, INT16 w);

// Define a Mat4f struct
typedef struct mat4f {
    Vec4f r1, r2, r3, r4;
} Mat4f;

// Setter for Mat4f struct properties
void setRows4f(Mat4f *m, Vec4f r1, Vec4f r2, Vec4f r3, Vec4f r4);

#endif