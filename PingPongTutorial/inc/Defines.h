#pragma once

#ifndef _DEFINES_H_
#define _DEFINES_H_

struct Vector
{
    double x;
    double y;

    Vector() : x(0.0), y(0.0) {}
    Vector(double _x, double _y) : x(_x), y(_y) {}

    bool operator==(const Vector& obj) const
    {
        return x == obj.x && y == obj.y;
    }

    bool operator!=(const Vector& obj) const
    {
        return !(*this == obj);
    }

    Vector operator+(const Vector& obj) const
    {
        return { x + obj.x, y + obj.y };
    }

    Vector operator-(const Vector& obj) const
    {
        return { x + obj.x, y + obj.y };
    }

    Vector operator-() const
    {
        return { -x, -y };
    }

    friend Vector operator*(const Vector& lhs, double rhs)
    {
        return { lhs.x * rhs, lhs.y * rhs };
    }

    friend Vector operator*(double lhs, const Vector& rhs)
    {
        return rhs * lhs;
    }

    friend Vector operator/(const Vector& lhs, double rhs)
    {
        return { lhs.x / rhs, lhs.y / rhs };
    }

    friend Vector operator/(double lhs, const Vector& rhs)
    {
        return rhs / lhs;
    }
};

using Coordinate = Vector;

#endif
