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


struct Rectangle
{
    union
    {
        Coordinate pos;
        struct { double x; double y; };
    };
    double width;
    double height;

    Rectangle() : x(0.0), y(0.0), width(0.0), height(0.0) {}
    Rectangle(double _x, double _y, double _width, double _height)
        : x(_x), y(_y), width(_width), height(_height) {}

    Coordinate GetCenter() const
    {
        return { x + width * 0.5, y + height * 0.5 };
    }

    Coordinate Intersect(const Rectangle& rect) const
    {
        return Coordinate();
    }

    bool Contains(const Coordinate& coord) const
    {
        return ((x < coord.x && coord.x < x + width) && (y < coord.y && coord.y < y + height));
    }
};

#endif
