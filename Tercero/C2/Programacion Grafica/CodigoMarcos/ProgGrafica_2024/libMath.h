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
            float v[4];
        };
    }vec4float;
   

    typedef struct {
        union {
            float mat2D[4][4];
            float mat[16];
            vec4float matV[4];
        };
    }matrix4x4f;



    inline vec4float make_vec4float(float x, float y, float z, float w) {
        vec4float v;
        v.v[0] = x;
        v.v[1] = y;
        v.v[2] = z;
        v.v[3] = w;
        return v;
    }
    inline float length(vec4float v)
    {
        float length = std::sqrt(v.v[0] * v.v[0] +
            v.v[1] * v.v[1] +
            v.v[2] * v.v[2]);
        return length;
    }
    inline  vec4float normalize(vec4float v)
    {
        float length = std::sqrt(v.v[0] * v.v[0] + v.v[1] * v.v[1] + v.v[2] * v.v[2]);
        return make_vec4float(v.v[0] / length, v.v[1] / length, v.v[2] / length, 0.0f);
    }

    inline  float dot(vec4float v1, vec4float v2)
    {
        return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2] + v1.v[3] * v2.v[3];
    }

    inline  float dot3f(vec4float v1, vec4float v2)
    {
        return v1.v[0] * v2.v[0] + v1.v[1] * v2.v[1] + v1.v[2] * v2.v[2];
    }
    inline  vec4float cross(vec4float v1, vec4float v2)
    {
        return make_vec4float(v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],
            -v1.v[0] * v2.v[2] + v1.v[2] * v2.v[0],
            v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0], 0.0f);

    }

    inline  vec4float operator+(vec4float v1, vec4float v2) {
        return make_vec4float(v1.v[0] + v2.v[0], v1.v[1] + v2.v[1], v1.v[2] + v2.v[2], v1.v[3] + v2.v[3]);
    }

    inline  vec4float operator-(vec4float v1, vec4float v2) {
        return make_vec4float(v1.v[0] - v2.v[0], v1.v[1] - v2.v[1], v1.v[2] - v2.v[2], v1.v[3] - v2.v[3]);
    }

    inline float operator* (vec4float v1, vec4float v2) {

        float res = 0;
        res = v1.x * v2.x +
            v1.y * v2.y +
            v1.z * v2.z +
            v1.w * v2.w;
        return res;
    }

    inline  vec4float operator*(vec4float v1, float v2)
    {
        return make_vec4float(v1.v[0] * v2, v1.v[1] * v2, v1.v[2] * v2, v1.v[3] * v2);

    }
    inline  vec4float operator*(float v2, vec4float v1)
    {
        return make_vec4float(v1.v[0] * v2, v1.v[1] * v2, v1.v[2] * v2, v1.v[3] * v2);

    }

    inline  vec4float operator/(float v2, vec4float v1)
    {
        return make_vec4float(v1.v[0] / v2, v1.v[1] / v2, v1.v[2] / v2, v1.v[3] / v2);

    }

    inline  vec4float operator/(vec4float v1, float v2)
    {
        return make_vec4float(v1.v[0] / v2, v1.v[1] / v2, v1.v[2] / v2, v1.v[3] / v2);

    }

    inline float distance(vec4float v1, vec4float v2)
    {
        vec4float direction = v1 - v2;
        return length(direction);

    }

    inline  bool operator==(vec4float v1, vec4float v2)
    {
        return memcmp(&v1, &v2, sizeof(vec4float)) == 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);
    }

    inline  bool operator!=(vec4float v1, vec4float v2)
    {
        return memcmp(&v1, &v2, sizeof(vec4float)) != 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);
    }

    inline  bool operator<(vec4float v1, vec4float v2)
    {
        return memcmp(&v1, &v2, sizeof(vec4float)) < 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);


    }

    inline  bool operator>(vec4float v1, vec4float v2)
    {
        return memcmp(&v1, &v2, sizeof(vec4float)) < 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);


    }

    inline  bool operator<=(vec4float v1, vec4float v2)
    {
        return   memcmp(&v1, &v2, sizeof(vec4float)) <= 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);


    }


    inline  bool operator>=(vec4float v1, vec4float v2)
    {
        return   memcmp(&v1, &v2, sizeof(vec4float)) >= 0;//(v1.v[0] == v2.v[0]) && (v1.v[1] == v2.v[1]) && (v1.v[2] == v2.v[2]) && (v1.v[3] = v2.v[3]);

    }
    inline vec4float operator*(matrix4x4f m1, vec4float v1)
    {
        vec4float res = { 0,0,0,0 };
        for (int j = 0;j < 4;j++)
        {
            res.v[j] = m1.matV[j] * v1;
        }
        return res;
    }


    /*inline std::ostream& operator<<(std::ostream& os, vec4float& v1)
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

    inline matrix4x4f make_identityf() {
        matrix4x4f m;
        memset(&m, 0, sizeof(matrix4x4f));
        //m.x0 = m.y1 = m.z2 = m.w3 = 1.0f;
        m.mat2D[0][0] = m.mat2D[1][1] = m.mat2D[2][2] = m.mat2D[3][3] = 1.0f;
        return m;

    }


    inline matrix4x4f make_traslate(float x, float y, float z)
    {
        matrix4x4f m = { .matV = {
            {1, 0, 0, x},
            {0, 1, 0, y},
            {0, 0, 1, z},
            {0, 0, 0, 1}} };

        return m;
    }
    inline matrix4x4f transpose(matrix4x4f m1)
    {
        matrix4x4f m = { .mat = {m1.mat2D[0][0],m1.mat2D[1][0],m1.mat2D[2][0],m1.mat2D[3][0],
                                m1.mat2D[0][1], m1.mat2D[1][1], m1.mat2D[2][1], m1.mat2D[3][1],
                                m1.mat2D[0][2], m1.mat2D[1][2], m1.mat2D[2][2], m1.mat2D[3][2],
                                m1.mat2D[0][3], m1.mat2D[1][3], m1.mat2D[2][3], m1.mat2D[3][3]}
        };
        return m;
    }
    inline matrix4x4f operator*(matrix4x4f m1, matrix4x4f m2)
    {
        matrix4x4f res = make_identityf();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++)
            {
                res.mat2D[i][j] = 0.0f;
                for (int k = 0; k < 4; k++)
                {
                    res.mat2D[i][j] += m1.mat2D[i][k] * m2.mat2D[k][j];
                }
            }
        }

        return res;
    }

    inline matrix4x4f make_rotate(float x, float y, float z) {
        matrix4x4f m = make_identityf();

        matrix4x4f mx = make_identityf(), my = make_identityf(), mz = make_identityf();
        mx.mat2D[1][1] = (float)cos(toRadians(x));
        mx.mat2D[1][2] = -1.0f * (float)sin(toRadians(x));
        mx.mat2D[2][1] = (float)sin(toRadians(x));
        mx.mat2D[2][2] = (float)cos(toRadians(x));

        my.mat2D[0][0] = (float)cos(toRadians(y));
        my.mat2D[0][2] = (float)sin(toRadians(y));
        my.mat2D[2][0] = -1.0f * (float)sin(toRadians(y));
        my.mat2D[2][2] = (float)cos(toRadians(y));

        mz.mat2D[0][0] = (float)cos(toRadians(z));
        mz.mat2D[0][1] = -1.0f * (float)sin(toRadians(z));
        mz.mat2D[1][0] = (float)sin(toRadians(z));
        mz.mat2D[1][1] = (float)cos(toRadians(z));

        return mx * my * mz;

     }
    inline matrix4x4f make_rotateX(float x) {
        matrix4x4f m = make_identityf();

        matrix4x4f mx = make_identityf(), my = make_identityf(), mz = make_identityf();
        mx.mat2D[1][1] = (float)cos(toRadians(x));
        mx.mat2D[1][2] = -1.0f * (float)sin(toRadians(x));
        mx.mat2D[2][1] = (float)sin(toRadians(x));
        mx.mat2D[2][2] = (float)cos(toRadians(x));

        return mx;

    }

    inline matrix4x4f make_rotateY(float y) {
        matrix4x4f m = make_identityf();

        matrix4x4f mx = make_identityf(), my = make_identityf(), mz = make_identityf();
        my.mat2D[0][0] = (float)cos(toRadians(y));
        my.mat2D[0][2] = (float)sin(toRadians(y));
        my.mat2D[2][0] = -1.0f * (float)sin(toRadians(y));
        my.mat2D[2][2] = (float)cos(toRadians(y));

        return my;

    }






    inline matrix4x4f make_scale(float x, float y, float z) {
        matrix4x4f m = make_identityf();
        m.mat2D[0][0] = x;
        m.mat2D[1][1] = y;
        m.mat2D[2][2] = z;
        return m;
    }

};
