#ifndef LINALG_H
#define LINALG_H

#define P_NORM_1 749056 // Approximately 1 / ( tan( ( 10 / 2 ) * ( pi / 180 ) ) )
//#define P_NORM_1 371456 // Approximately 1 / ( tan( ( 20 / 2 ) * ( pi / 180 ) ) )
//#define P_NORM_1 244480 // Approximately 1 / ( tan( ( 30 / 2 ) * ( pi / 180 ) ) )
//#define P_NORM_1 179968 // Approximately 1 / ( tan( ( 40 / 2 ) * ( pi / 180 ) ) )
//#define P_NORM_1 140288 // Approximately 1 / ( tan( ( 50 / 2 ) * ( pi / 180 ) ) )
//#define P_NORM_1 113408 // Approximately 1 / ( tan( ( 60 / 2 ) * ( pi / 180 ) ) )
//#define P_NORM_1 93440 // Approximately 1 / ( tan( ( 70 / 2 ) * ( pi / 180 ) ) )
#define P_NORM_2 65536 // Approximately 256 / (256 - 0.5)
//#define P_NORM_2 66560 // Approximately 64 / (64 - 0.5)
#define P_NORM_3 32768 // Approximately (256 * 0.5) / (256 - 0.5)
//#define P_NORM_3 33024 // Approximaely (64 * 0.5) / (64 - 0.5)

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
void transformCoords(Vec3 *v, Mat3 m);

// Setter for Mat3 struct properties
void setRows3(Mat3 *m, Vec3 r1, Vec3 r2, Vec3 r3);

// Define a Vec4 struct
typedef struct vec4 {
	INT32 x, y, z, w;
} Vec4;

// Setter for Vec4 struct properties
void setCoords4(Vec4 *v, INT32 x, INT32 y, INT32 z, INT32 w);

// Convert a Vec3 to a Vec4
Vec4 vec3tovec4(Vec3 *v);

// Convert a Vec4 to a Vec3
Vec3 vec4tovec3(Vec4 *v);

// Define a Mat4 struct
typedef struct mat4 {
    Vec4 r1, r2, r3, r4;
} Mat4;

// Transform Vec4 coordinates using a Mat4
void projectCoords(Vec4 *v);

// Setter for Mat4 struct properties
void setRows4(Mat4 *m, Vec4 r1, Vec4 r2, Vec4 r3, Vec4 r4);

#endif