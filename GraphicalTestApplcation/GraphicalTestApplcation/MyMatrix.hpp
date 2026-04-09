#pragma once
#include <cmath>
#include <iostream>
#include<string>
#include "MyVector.hpp"
#include <raylib.h>

struct myMatrix
{
public:
    float m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11, m12, m13, m14, m15, m16;

    myMatrix()
    {
        m1 = 1;
        m2 = 0;
        m3 = 0;
        m4 = 0;
        m5 = 0;
        m6 = 1;
        m7 = 0;
        m8 = 0;
        m9 = 0;
        m10 = 0;
        m11 = 1;
        m12 = 0;
        m13 = 0;
        m14 = 0;
        m15 = 0;
        m16 = 1;
    }
    myMatrix(const myMatrix& other)
    {
        m1 = other.m1;
        m2 = other.m2;
        m3 = other.m3;
        m4 = other.m4;
        m5 = other.m5;
        m6 = other.m6;
        m7 = other.m7;
        m8 = other.m8;
        m9 = other.m9;
        m10 = other.m10;
        m11 = other.m11;
        m12 = other.m12;
        m13 = other.m13;
        m14 = other.m14;
        m15 = other.m15;
        m16 = other.m16;
    }
    myMatrix(
        float mat4m1, float mat4m2, float mat4m3, float mat4m4,
        float mat4m5, float mat4m6, float mat4m7, float mat4m8,
        float mat4m9, float mat4m10, float mat4m11, float mat4m12,
        float mat4m13, float mat4m14, float mat4m15, float mat4m16)
    {
        m1 = mat4m1;
        m2 = mat4m2;
        m3 = mat4m3;
        m4 = mat4m4;
        m5 = mat4m5;
        m6 = mat4m6;
        m7 = mat4m7;
        m8 = mat4m8;
        m9 = mat4m9;
        m10 = mat4m10;
        m11 = mat4m11;
        m12 = mat4m12;
        m13 = mat4m13;
        m14 = mat4m14;
        m15 = mat4m15;
        m16 = mat4m16;
    }

    myMatrix operator = (Matrix& other)
    {
        myMatrix temp;
        temp.m1 = m1 = other.m0;
        temp.m2 = m2 = other.m1;
        temp.m3 = m3 = other.m2;
        temp.m4 = m4 = other.m3;

        temp.m5 = m5 = other.m4;
        temp.m6 = m6 = other.m5;
        temp.m7 = m7 = other.m6;
        temp.m8 = m8 = other.m7;

        temp.m9 = m9 = other.m8;
        temp.m10 = m10 = other.m9;
        temp.m11 = m11 = other.m10;
        temp.m12 = m12 = other.m11;

        temp.m13 = m13 = other.m12;
        temp.m14 = m14 = other.m13;
        temp.m15 = m15 = other.m14;
        temp.m16 = m16 = other.m15;

        return temp;
    }
    myMatrix operator = (const Matrix& other)
    {
        myMatrix temp;
        temp.m1 = m1 = other.m0;
        temp.m2 = m2 = other.m1;
        temp.m3 = m3 = other.m2;
        temp.m4 = m4 = other.m3;

        temp.m5 = m5 = other.m4;
        temp.m6 = m6 = other.m5;
        temp.m7 = m7 = other.m6;
        temp.m8 = m8 = other.m7;

        temp.m9 = m9 = other.m8;
        temp.m10 = m10 = other.m9;
        temp.m11 = m11 = other.m10;
        temp.m12 = m12 = other.m11;

        temp.m13 = m13 = other.m12;
        temp.m14 = m14 = other.m13;
        temp.m15 = m15 = other.m14;
        temp.m16 = m16 = other.m15;

        return temp;
    }
    myMatrix operator = (myMatrix& other)
    {
        myMatrix temp;
        temp.m1 = m1 = other.m1;
        temp.m2 = m2 = other.m2;
        temp.m3 = m3 = other.m3;
        temp.m4 = m4 = other.m4;

        temp.m5 = m5 = other.m5;
        temp.m6 = m6 = other.m6;
        temp.m7 = m7 = other.m7;
        temp.m8 = m8 = other.m8;

        temp.m9 = m9 = other.m9;
        temp.m10 = m10 = other.m10;
        temp.m11 = m11 = other.m11;
        temp.m12 = m12 = other.m12;

        temp.m13 = m13 = other.m13;
        temp.m14 = m14 = other.m14;
        temp.m15 = m15 = other.m15;
        temp.m16 = m16 = other.m16;

        return temp;
    }
    myMatrix operator = (const myMatrix& other)
    {
        myMatrix temp;
        temp.m1 = m1 = other.m1;
        temp.m2 = m2 = other.m2;
        temp.m3 = m3 = other.m3;
        temp.m4 = m4 = other.m4;

        temp.m5 = m5 = other.m5;
        temp.m6 = m6 = other.m6;
        temp.m7 = m7 = other.m7;
        temp.m8 = m8 = other.m8;

        temp.m9 = m9 = other.m9;
        temp.m10 = m10 = other.m10;
        temp.m11 = m11 = other.m11;
        temp.m12 = m12 = other.m12;

        temp.m13 = m13 = other.m13;
        temp.m14 = m14 = other.m14;
        temp.m15 = m15 = other.m15;
        temp.m16 = m16 = other.m16;

        return temp;
    }

    friend myMatrix operator *(myMatrix a, myMatrix b)
    {
        return a *= b;
    }
    friend myMatrix& operator *=(myMatrix& lhs, myMatrix rhs)
    {
        lhs.m1 = lhs.m1 * rhs.m1 + lhs.m5 * rhs.m2 + lhs.m9 * rhs.m3 + lhs.m13 * rhs.m4;
        lhs.m2 = lhs.m2 * rhs.m1 + lhs.m6 * rhs.m2 + lhs.m10 * rhs.m3 + lhs.m14 * rhs.m4;
        lhs.m3 = lhs.m3 * rhs.m1 + lhs.m7 * rhs.m2 + lhs.m11 * rhs.m3 + lhs.m15 * rhs.m4;
        lhs.m4 = lhs.m4 * rhs.m1 + lhs.m8 * rhs.m2 + lhs.m12 * rhs.m3 + lhs.m16 * rhs.m4;

        lhs.m5 = lhs.m1 * rhs.m5 + lhs.m5 * rhs.m6 + lhs.m9 * rhs.m7 + lhs.m13 * rhs.m8;
        lhs.m6 = lhs.m2 * rhs.m5 + lhs.m6 * rhs.m6 + lhs.m10 * rhs.m7 + lhs.m14 * rhs.m8;
        lhs.m7 = lhs.m3 * rhs.m5 + lhs.m7 * rhs.m6 + lhs.m11 * rhs.m7 + lhs.m15 * rhs.m8;
        lhs.m8 = lhs.m4 * rhs.m5 + lhs.m8 * rhs.m6 + lhs.m12 * rhs.m7 + lhs.m16 * rhs.m8;

        lhs.m9 = lhs.m1 * rhs.m9 + lhs.m5 * rhs.m10 + lhs.m9 * rhs.m11 + lhs.m13 * rhs.m12;
        lhs.m10 = lhs.m2 * rhs.m1 + lhs.m6 * rhs.m2 + lhs.m10 * rhs.m11 + lhs.m14 * rhs.m12;
        lhs.m11 = lhs.m3 * rhs.m1 + lhs.m7 * rhs.m2 + lhs.m11 * rhs.m11 + lhs.m15 * rhs.m12;
        lhs.m12 = lhs.m4 * rhs.m1 + lhs.m8 * rhs.m2 + lhs.m12 * rhs.m11 + lhs.m16 * rhs.m12;

        lhs.m13 = lhs.m1 * rhs.m13 + lhs.m5 * rhs.m14 + lhs.m9 * rhs.m15 + lhs.m13 * rhs.m16;
        lhs.m14 = lhs.m2 * rhs.m13 + lhs.m6 * rhs.m14 + lhs.m10 * rhs.m15 + lhs.m14 * rhs.m16;
        lhs.m15 = lhs.m3 * rhs.m13 + lhs.m7 * rhs.m14 + lhs.m11 * rhs.m15 + lhs.m15 * rhs.m16;
        lhs.m16 = lhs.m4 * rhs.m13 + lhs.m8 * rhs.m14 + lhs.m12 * rhs.m15 + lhs.m16 * rhs.m16;

        return lhs;
    }

    friend bool operator==(myMatrix lhs, myMatrix equal)
    {
        return  lhs.m1 == equal.m1 && lhs.m2 == equal.m2 && lhs.m3 == equal.m3 && lhs.m4 == equal.m4 &&
            lhs.m5 == equal.m5 && lhs.m6 == equal.m6 && lhs.m7 == equal.m7 && lhs.m8 == equal.m8 &&
            lhs.m9 == equal.m9 && lhs.m10 == equal.m10 && lhs.m11 == equal.m11 && lhs.m12 == equal.m12 &&
            lhs.m13 == equal.m13 && lhs.m14 == equal.m14 && lhs.m15 == equal.m15 && lhs.m16 == equal.m16;
    }
    friend bool operator!=(myMatrix lhs, myMatrix rhs)
    {
        return lhs.m1 != rhs.m1 && lhs.m2 != rhs.m2 && lhs.m3 != rhs.m3 && lhs.m4 != rhs.m4 &&
            lhs.m5 != rhs.m5 && lhs.m6 != rhs.m6 && lhs.m7 != rhs.m7 && lhs.m8 != rhs.m8 &&
            lhs.m9 != rhs.m9 && lhs.m10 != rhs.m10 && lhs.m11 != rhs.m11 && lhs.m12 != rhs.m12 &&
            lhs.m13 != rhs.m13 && lhs.m14 != rhs.m14 && lhs.m15 != rhs.m15 && lhs.m16 != rhs.m16;
    }

    float& operator[](int i)
    {
        switch (i)
        {
        case 0:
            return m1;
        case 1:
            return m2;
        case 2:
            return m3;
        case 3:
            return m4;
        case 4:
            return m5;
        case 5:
            return m6;
        case 6:
            return m7;
        case 7:
            return m8;
        case 8:
            return m9;
        case 9:
            return m10;
        case 10:
            return m11;
        case 11:
            return m12;
        case 12:
            return m13;
        case 13:
            return m14;
        case 14:
            return m15;
        case 15:
            return m16;
        }

        throw;
    }
    const float& operator[](int i)const
    {
        switch (i)
        {
        case 0:
            return m1;
        case 1:
            return m2;
        case 2:
            return m3;
        case 3:
            return m4;
        case 4:
            return m5;
        case 5:
            return m6;
        case 6:
            return m7;
        case 7:
            return m8;
        case 8:
            return m9;
        case 9:
            return m10;
        case 10:
            return m11;
        case 11:
            return m12;
        case 12:
            return m13;
        case 13:
            return m14;
        case 14:
            return m15;
        case 15:
            return m16;
        }

        throw;
    }

    static myMatrix MakeRotateX(float rad)
    {
        myMatrix result = {
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f };

        float cosResult = cosf(rad);
        float sinResult = sinf(rad);

        result.m6 = cosResult;
        result.m7 = -sinResult;
        result.m10 = sinResult;
        result.m11 = cosResult;

        return result;
    }
    static myMatrix MakeRotateY(float rad)
    {
        myMatrix result = {
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f };

        float cosResult = cosf(rad);
        float sinResult = sinf(rad);

        result.m1 = cosResult;
        result.m3 = sinResult;
        result.m9 = -sinResult;
        result.m11 = cosResult;

        return result;
    }
    static myMatrix MakeRotateZ(float rad)
    {
        myMatrix result = {
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f };

        float cosResult = cosf(rad);
        float sinResult = sinf(rad);

        result.m1 = cosResult;
        result.m2 = sinResult;
        result.m5 = -sinResult;
        result.m6 = cosResult;

        return result;
    }

    static myMatrix MakeScale(float x, float y, float z)
    {
        myMatrix result = {
            x, 0.f, 0.f, 0.f,
            0.f, y, 0.f, 0.f,
            0.f, 0.f, z, 0.f,
            0.f, 0.f, 0.f, 1.f
        };
        return result;
    }
    static myMatrix MakeTranslation(float x, float y, float z)
    {
        myMatrix result = {
            1.f, 0.f, 0.f, x,
            0.f, 1.f, 0.f, y,
            0.f, 0.f, 1.f, z,
            0.f, 0.f, 0.f, 1.f
        };
        return result;
    }

    myMatrix myMatrixIdentity()
    {
        myMatrix result = {
            1.f, 0.f, 0.f, 0.f,
            0.f, 1.f, 0.f, 0.f,
            0.f, 0.f, 1.f, 0.f,
            0.f, 0.f, 0.f, 1.f };
        return result;
    }

    bool IsApproximatelyEqual(myMatrix rhs, float epsilon = 1e-4f)const
    {
        float deltas[] = {
            std::abs(m1 - rhs.m1),
            std::abs(m2 - rhs.m2),
            std::abs(m3 - rhs.m3),
            std::abs(m4 - rhs.m4),
            std::abs(m5 - rhs.m5),
            std::abs(m6 - rhs.m6),
            std::abs(m7 - rhs.m7),
            std::abs(m8 - rhs.m8),
            std::abs(m9 - rhs.m9),
            std::abs(m10 - rhs.m10),
            std::abs(m11 - rhs.m11),
            std::abs(m12 - rhs.m12),
            std::abs(m13 - rhs.m13),
            std::abs(m14 - rhs.m14),
            std::abs(m15 - rhs.m15),
            std::abs(m16 - rhs.m16)
        };
        const int arraySize = sizeof(deltas) / sizeof(deltas[0]);
        for (int i = 0; i < arraySize; ++i)
        {
            if (!(deltas[i] <= epsilon))
            {
                return false;
            }
        }
        return true;
    }
    Matrix MatrixConvertRaylib(myMatrix mat)
    {
        Matrix tempConvert;
        tempConvert.m0 = mat.m1;
        tempConvert.m1 = mat.m2;
        tempConvert.m2 = mat.m3;
        tempConvert.m3 = mat.m4;
        tempConvert.m4 = mat.m5;
        tempConvert.m5 = mat.m6;
        tempConvert.m6 = mat.m7;
        tempConvert.m7 = mat.m8;
        tempConvert.m8 = mat.m9;
        tempConvert.m9 = mat.m10;
        tempConvert.m10 = mat.m11;
        tempConvert.m11 = mat.m12;
        tempConvert.m12 = mat.m13;
        tempConvert.m13 = mat.m14;
        tempConvert.m14 = mat.m15;
        tempConvert.m15 = mat.m16;
        return tempConvert;
    }
};