#ifndef AC_VEC2_H
#define AC_VEC2_H

#include <math.h>

typedef struct Vec2f {
    float x, y;
} Vec2f;

typedef struct Vec2 {
    int x, y;
} Vec2;

#define VEC2F(x, y) (Vec2f){x, y}
#define VEC2(x, y)(Vec2){x, y}

Vec2f Vec2f_add(Vec2f a, Vec2f b);
Vec2f Vec2f_sub(Vec2f a, Vec2f b);
Vec2f Vec2f_mul(Vec2f a, Vec2f b);
Vec2f Vec2f_div(Vec2f a, Vec2f b);
Vec2f Vec2f_sca(Vec2f a, float b);

// Returns 1 (true) if the vectors match, 0 (false) if otherwise.
int Vec2f_cmp(Vec2f a, Vec2f b);

Vec2 Vec2_add(Vec2 a, Vec2 b);
Vec2 Vec2_sub(Vec2 a, Vec2 b);
Vec2 Vec2_mul(Vec2 a, Vec2 b);
Vec2 Vec2_div(Vec2 a, Vec2 b);
Vec2 Vec2_sca(Vec2 a, int b);

// Convert a Vec2 to a Vec2f
Vec2f Vec2_float(Vec2 a);

// Returns 1 (true) if the vectors match, 0 (false) if otherwise.
int Vec2_cmp(Vec2 a, Vec2 b);

#ifdef AC_VEC2_IMPL

Vec2f Vec2f_add(Vec2f a, Vec2f b) { return VEC2F(a.x + b.x, a.y + b.y); }
Vec2f Vec2f_sub(Vec2f a, Vec2f b) { return VEC2F(a.x - b.x, a.y - b.y); }
Vec2f Vec2f_mul(Vec2f a, Vec2f b) { return VEC2F(a.x * b.x, a.y * b.y); }
Vec2f Vec2f_div(Vec2f a, Vec2f b) { return VEC2F(a.x / b.x, a.y / b.y); }
Vec2f Vec2f_sca(Vec2f a, float b) { return VEC2F(a.x * b, a.y * b); }

int Vec2f_cmp(Vec2f a, Vec2f b) { 
    const float epsilon = 1e-6f;
    return fabsf(a.x - b.x) < epsilon && fabsf(a.y - b.y) < epsilon;
}

Vec2 Vec2_add(Vec2 a, Vec2 b) { return VEC2(a.x + b.x, a.y + b.y); }
Vec2 Vec2_sub(Vec2 a, Vec2 b) { return VEC2(a.x - b.x, a.y - b.y); }
Vec2 Vec2_mul(Vec2 a, Vec2 b) { return VEC2(a.x * b.x, a.y * b.y); }
Vec2 Vec2_div(Vec2 a, Vec2 b) { return VEC2(a.x / b.x, a.y / b.y); }
Vec2 Vec2_sca(Vec2 a, int b) { return VEC2(a.x * b, a.y * b); }
int Vec2_cmp(Vec2 a, Vec2 b) {return a.x == b.x && a.y == b.y; }

Vec2f Vec2_float(Vec2 a) {return VEC2F(a.x, a.y);}
#endif

#endif