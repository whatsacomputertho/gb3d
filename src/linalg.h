#ifndef LINALG_H
#define LINALG_H

// Define a Vec3 struct
typedef struct vec3 {
	INT32 x, y, z;
} Vec3;

// Setter for Vec3 struct properties
void setCoords3(Vec3 *v, INT32 x, INT32 y, INT32 z);

// Define a Mat3 struct
typedef struct mat3 {
    Vec3 r1, r2, r3;
} Mat3;

// Transform Vec3 coordinates using a Mat3
void transformCoords3(Vec3 *v, Mat3 m);

// Setter for Mat3 struct properties
void setRows3(Mat3 *m, Vec3 r1, Vec3 r2, Vec3 r3);

// Define a Vec4 struct
typedef struct vec4 {
	INT32 x, y, z, w;
} Vec4;

// Setter for Vec4 struct properties
void setCoords4(Vec4 *v, INT32 x, INT32 y, INT32 z, INT32 w);

// Define a Mat4 struct
typedef struct mat4 {
    Vec4 r1, r2, r3, r4;
} Mat4;

// Transform Vec4 coordinates using a Mat4
void transformCoords4(Vec4 *v, Mat4 m);

// Setter for Mat4 struct properties
void setRows4(Mat4 *m, Vec4 r1, Vec4 r2, Vec4 r3, Vec4 r4);

#endif