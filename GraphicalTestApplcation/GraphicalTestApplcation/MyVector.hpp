#pragma once
#include <cmath>
#include <iostream>
#include<string>
#include "MyMatrix.hpp"
#include <raylib.h>

struct myVector
{
public:
	float x, y = 0.f;

    myVector()
    {
        x = 0;
        y = 0;
    }
    myVector(const myVector& other)
    {
        x = other.x;
        y = other.y;
    }
    myVector(float vec3x, float vec3y)
    {
        x = vec3x;
        y = vec3y;
    }

    myVector operator + (myVector& v3Add)
    {
        return {
         x + v3Add.x,
        y + v3Add.y,
        };
    }
    myVector operator - (myVector& v3Subtract)
    {
        return {
         x - v3Subtract.x,
        y - v3Subtract.y,
        };
    }
    const myVector operator - (const myVector& v3Subtract)
    {
        return {
         x - v3Subtract.x,
        y - v3Subtract.y,
        };
    }

    myVector operator * (myVector& v3Multiply)
    {
        return {
        x * v3Multiply.x,
        y * v3Multiply.y
        };
    }
    myVector operator * (float v3ScalarMult)
    {
        return myVector(x * v3ScalarMult, y * v3ScalarMult);
    }
    myVector operator / (float v3ScalarDivide)
    {
        return myVector(x / v3ScalarDivide, y / v3ScalarDivide);
    }

     myVector& operator = (myVector& v3Assignment)
    {
        myVector tempAssignment;
        tempAssignment.x = x = v3Assignment.x;
        tempAssignment.y = y = v3Assignment.y;
        return tempAssignment;
    }
     myVector& operator = (const myVector& v3Assignment)
     {
         myVector tempAssignment;
         tempAssignment.x = x = v3Assignment.x;
         tempAssignment.y = y = v3Assignment.y;
         return tempAssignment;
     }
     myVector& operator = (Vector2 v3Assignment)
     {
         myVector tempAssignment;
         tempAssignment.x = x = v3Assignment.x;
         tempAssignment.y = y = v3Assignment.y;
         return tempAssignment;
     }

    myVector operator += (myVector& v3AddAssign)
    {
        myVector tempAddAssign;
        tempAddAssign.x = x += v3AddAssign.x;
        tempAddAssign.y = y += v3AddAssign.y;
        return tempAddAssign;
    }
    myVector operator -= (myVector& v3SubtractAssign)
    {
        myVector tempSubtractAssign;
        tempSubtractAssign.x = x -= v3SubtractAssign.x;
        tempSubtractAssign.y = y -= v3SubtractAssign.y;
        return tempSubtractAssign;
    }
    myVector operator *= (myVector& v3MulitplyAssign)
    {
        myVector tempMultiplyAssign;
        tempMultiplyAssign.x = x *= v3MulitplyAssign.x;
        tempMultiplyAssign.y = y *= v3MulitplyAssign.y;
        return tempMultiplyAssign;
    }
    myVector operator *= (const float v3ScalarMultAssign)
    {
        return myVector(x *= v3ScalarMultAssign, y *= v3ScalarMultAssign);
    }
    myVector operator /= (const float v3ScalarDivideAssign)
    {
        return myVector(x /= v3ScalarDivideAssign, y /= v3ScalarDivideAssign);
    }

    myVector operator -() const
    {
        return { -x, -y };
    }

    friend bool operator == (const myVector lhs, const myVector& v3Equality)
    {
        return lhs.x == v3Equality.x && lhs.y == v3Equality.y;
    }
    bool operator != (myVector& v3Inequality)const
    {
        return x != v3Inequality.x && y != v3Inequality.y;
    }
    friend bool operator < (myVector lhs, myVector v3LessThan)
    {
        float v3a = v3LessThan.Magnitude();
        float v3b = lhs.Magnitude();
        if ((v3b < v3a) == true)
        {
            return true;
        }
        else if ((v3b < v3a) == false)
        {
            return false;
        }
        else if ((v3a < v3b) == false)
        {
            return false;
        }
    }
    float& operator[] (int i)
    {
        switch (i)
        {
        case 0:
            return x;
        case 1:
            return y;
        }

        throw;
    }
    const float& operator[] (int i)const
    {
        switch (i)
        {
        case 0:
            return x;
        case 1:
            return y;
        }

        throw;

    }

    //myVector's member functions
    bool IsApproximatelyEqual(myVector rhs, float epsilon = 1e-4f) const
    {
        float deltas[] = {
            std::abs(x - rhs.x),
            std::abs(y - rhs.y),
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

    float Dot(myVector rhs) const
    {
        return x * rhs.x + y * rhs.y;
    }
   

    float Magnitude() const
    {
        return std::hypot(x, y);
    }
    void Normalise()
    {
        float mag = std::hypot(x, y);
        if (mag == 0.f)
        {
            return;
        }
        x /= mag;
        y /= mag;
        
    }
    myVector Normalised() const
    {
        myVector result{ *this };
        result.Normalise();
        return result;
    }

    float AngleBetween(myVector other) const
    {
        float dot = x * other.x + y * other.y;
        float magLeft = std::hypot(x, y);
        float magRight = std::hypot(other.x, other.y);
        float acosResult = std::acos(dot / (magLeft * magRight));
        return acosResult;
    }
    float Distance(myVector rhs) const
    {
        myVector diff = myVector{ rhs.x - x, rhs.y - y};
        return diff.Magnitude();
    }
    float Angle2D() const
    {
        return std::atan2(y, x);
    }
    myVector myVectorTransform(myVector v, myMatrix mat)
    {
        myVector result = { 0 ,0 };

        float x = v.x;
        float y = v.y;
        float z = 0;

        result.x = mat.m1 * x + mat.m5 * y + mat.m9 * z + mat.m13;
        result.y = mat.m2 * x + mat.m6 * y + mat.m10 * z + mat.m14;

        return result;
    }
    Vector2 ConvertRaylib(myVector v)
    {
        Vector2 convert;
        convert.x = v.x;
        convert.y = v.y;
        return convert;
    }
};