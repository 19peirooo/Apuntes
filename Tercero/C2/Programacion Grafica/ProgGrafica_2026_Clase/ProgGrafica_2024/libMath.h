#pragma once
#include "common.h"
#define M_PI 3.1415


using namespace std;
namespace libMath {
    typedef struct {
        union {
            struct {
                float x;
                float y;
                float z;
                float w;
            };
            struct {
                float r;
                float g;
                float b;
                float a;
            };
            float v[4];
        };
    }Vector4f;
   

    typedef struct {
        union {
            float matriz[4][4];
            float m[16];
            Vector4f t[4];
        };
    }Matrix4x4f;



    inline Vector4f make_vector4f(float x, float y, float z, float w) {
        Vector4f v;
        v.v[0] = x;
        v.v[1] = y;
        v.v[2] = z;
        v.v[3] = w;
        return v;
    }
    inline float length(Vector4f v)
    {
        float length = std::sqrt(v.v[0] * v.v[0] +
            v.v[1] * v.v[1] +
            v.v[2] * v.v[2]);
        return length;
    }
    inline  Vector4f normalize(Vector4f v)
    {
        float length = std::sqrt(v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]);
        return make_vector4f(v.v[0] / length, v.v[1] / length, v.v[2] / length, 0.0f);
    }

    inline  float dot(Vector4f v1, Vector4f v2)
    {
        return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2] + v1.v[3] * v2.v[3];
    }

    inline  float dot3f(Vector4f v1, Vector4f v2)
    {
        return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
    }
    inline  Vector4f operator^(Vector4f v1, Vector4f v2)
    {
        return make_vector4f(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
            -v1.v[0] * v2.v[2] + v1.v[2] * v2.v[0],
            v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0], 0.0f);

    }

    inline  Vector4f operator+(Vector4f v1, Vector4f v2) {
        return make_vector4f(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2], v1.v[3] + v2.v[3]);
    }

    inline  Vector4f operator-(Vector4f v1, Vector4f v2) {
        return make_vector4f(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2], v1.v[3] - v2.v[3]);
    }

    inline float operator* (Vector4f v1, Vector4f v2) {

        float res = 0;
        res = v1.x * v2.x +
            v1.y * v2.y +
            v1.z * v2.z +
            v1.w * v2.w;
        return res;
    }

    inline  Vector4f operator*(Vector4f v1, float v2)
    {
        return make_vector4f(v1.v[0] * v2, v1.v[1] * v2, v1.v[2] * v2, v1.v[3] * v2);

    }
    inline  Vector4f operator*(float v2, Vector4f v1)
    {
        return make_vector4f(v1.v[0] * v2, v1.v[1] * v2, v1.v[2] * v2, v1.v[3] * v2);

    }

    inline  Vector4f operator/(float v2, Vector4f v1)
    {
        return make_vector4f(v1.v[0] / v2, v1.v[1] / v2, v1.v[2] / v2, v1.v[3] / v2);

    }

    inline  Vector4f operator/(Vector4f v1, float v2)
    {
        return make_vector4f(v1.v[0] / v2, v1.v[1] / v2, v1.v[2] / v2, v1.v[3] / v2);

    }

    inline float distance(Vector4f v1, Vector4f v2)
    {
        Vector4f direction = v1 - v2;
        return length(direction);

    }

    inline  bool operator==(Vector4f v1, Vector4f v2)
    {
        return memcmp(&v1, &v2, sizeof(Vector4f)) == 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);
    }

    inline  bool operator!=(Vector4f v1, Vector4f v2)
    {
        return memcmp(&v1, &v2, sizeof(Vector4f)) != 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);
    }

    inline  bool operator<(Vector4f v1, Vector4f v2)
    {
        return memcmp(&v1, &v2, sizeof(Vector4f)) < 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);


    }

    inline  bool operator>(Vector4f v1, Vector4f v2)
    {
        return memcmp(&v1, &v2, sizeof(Vector4f)) < 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);


    }

    inline  bool operator<=(Vector4f v1, Vector4f v2)
    {
        return   memcmp(&v1, &v2, sizeof(Vector4f)) <= 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);


    }


    inline  bool operator>=(Vector4f v1, Vector4f v2)
    {
        return   memcmp(&v1, &v2, sizeof(Vector4f)) >= 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);

    }
    inline Vector4f operator*(Matrix4x4f m1, Vector4f v1)
    {
        Vector4f res = { 0,0,0,0 };
        for (int j = 0;j < 4;j++)
        {
            res.v[j] = m1.t[j] * v1;
        }
        return res;
    }


    /*inline std::ostream& operator<<(std::ostream& os, Vector4f& v1)
    {
        os << "{" << v1.v[0] << "," << v1.v[1] << "," <<
            v1.v[2] << "," << v1.v[3] << "}\n";

        return os;
    }
    */

    inline float toRadians(float angle)
    {
        return (float)(angle * M_PI / (180.0f));
    }

    inline Matrix4x4f make_identityf() {
        Matrix4x4f m;
        memset(&m, 0, sizeof(Matrix4x4f));
        //m.x0 = m.y1 = m.z2 = m.w3 = 1.0f;
        m.matriz[0][0] = m.matriz[1][1] = m.matriz[2][2] = m.matriz[3][3] = 1.0f;
        return m;

    }


    inline Matrix4x4f make_traslate(float x, float y, float z)
    {
        Matrix4x4f m = { .t = {
            {1, 0, 0, x},
            {0, 1, 0, y},
            {0, 0, 1, z},
            {0, 0, 0, 1}} };

        return m;
    }
    inline Matrix4x4f transpose(Matrix4x4f m1)
    {
        Matrix4x4f m = { .m = {m1.matriz[0][0],m1.matriz[1][0],m1.matriz[2][0],m1.matriz[3][0],
                                m1.matriz[0][1], m1.matriz[1][1], m1.matriz[2][1], m1.matriz[3][1],
                                m1.matriz[0][2], m1.matriz[1][2], m1.matriz[2][2], m1.matriz[3][2],
                                m1.matriz[0][3], m1.matriz[1][3], m1.matriz[2][3], m1.matriz[3][3]}
        };
        return m;
    }
    inline Matrix4x4f operator*(Matrix4x4f m1, Matrix4x4f m2)
    {
        Matrix4x4f res = make_identityf();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
            {
                res.matriz[i][j] = 0.0f;
                for (int k = 0; k < 4; k++)
                {
                    res.matriz[i][j] += m1.matriz[i][k] * m2.matriz[k][j];
                }
            }
        }

        return res;
    }

    inline Matrix4x4f make_rotate(float x, float y, float z) {
        Matrix4x4f m = make_identityf();

        Matrix4x4f mx = make_identityf(), my = make_identityf(), mz = make_identityf();
        mx.matriz[1][1] = (float)cos(toRadians(x));
        mx.matriz[1][2] = -1.0f * (float)sin(toRadians(x));
        mx.matriz[2][1] = (float)sin(toRadians(x));
        mx.matriz[2][2] = (float)cos(toRadians(x));

        my.matriz[0][0] = (float)cos(toRadians(y));
        my.matriz[0][2] = (float)sin(toRadians(y));
        my.matriz[2][0] = -1.0f * (float)sin(toRadians(y));
        my.matriz[2][2] = (float)cos(toRadians(y));

        mz.matriz[0][0] = (float)cos(toRadians(z));
        mz.matriz[0][1] = -1.0f * (float)sin(toRadians(z));
        mz.matriz[1][0] = (float)sin(toRadians(z));
        mz.matriz[1][1] = (float)cos(toRadians(z));

        return mx * my * mz;

    }

    inline Matrix4x4f make_rotateX(float x) {

        Matrix4x4f mx = make_identityf();
        mx.matriz[1][1] = (float)cos(toRadians(x));
        mx.matriz[1][2] = -1.0f * (float)sin(toRadians(x));
        mx.matriz[2][1] = (float)sin(toRadians(x));
        mx.matriz[2][2] = (float)cos(toRadians(x));

        return mx;

    }

    inline Matrix4x4f make_rotateY(float y) {

        Matrix4x4f my = make_identityf();

        my.matriz[0][0] = (float)cos(toRadians(y));
        my.matriz[0][2] = (float)sin(toRadians(y));
        my.matriz[2][0] = -1.0f * (float)sin(toRadians(y));
        my.matriz[2][2] = (float)cos(toRadians(y));

        return my;

    }

    inline Matrix4x4f make_rotateZ(float x, float y, float z) {

        Matrix4x4f mz = make_identityf();

        mz.matriz[0][0] = (float)cos(toRadians(z));
        mz.matriz[0][1] = -1.0f * (float)sin(toRadians(z));
        mz.matriz[1][0] = (float)sin(toRadians(z));
        mz.matriz[1][1] = (float)cos(toRadians(z));

        return mz;

    }

    inline Matrix4x4f make_scale(float x, float y, float z) {
        Matrix4x4f m = make_identityf();
        m.matriz[0][0] = x;
        m.matriz[1][1] = y;
        m.matriz[2][2] = z;
        return m;
    }

};
