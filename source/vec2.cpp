#ifndef VEC2_CPP
#define VEC2_CPP

#include"vec2.hpp"
#include<iostream>

Vec2::Vec2():
        x{0.0f},
        y{0.0f} {}

Vec2::Vec2(float x, float y):
        x{x},
        y{y} {}

Vec2& Vec2::operator+=(Vec2 const& v){
    x = v.x + x;
    y = v.y + y;

    return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v){
    x = x - v.x;
    y = y - v.y;

    return *this;
}

Vec2& Vec2::operator*=(float v){
    x = x * v;
    y = y * v;

    return *this;
}

Vec2& Vec2::operator/=(float v){
    if (v == 0.0f)
    {
        std::cout << "Division durch 0, unmoeglich";
    }
    else
    {
        x = x / v;
        y = y / v;
    }
    return *this;
}

Vec2 operator+(Vec2 const & u , Vec2 const & v )
{
    return{u.x+v.x,u.y+v.y};
}

Vec2 operator-(Vec2 const & u, Vec2 const & v)
{
    return{u.x-v.x,u.y-v.y};
}

Vec2 operator*(Vec2 const& v, float s)
{
    return{v.x*s,v.y*s};
}

Vec2 operator/(Vec2 const& v, float s)
{
    if(s == 0){
        std::cout <<"Division durch 0, unmoeglich";
        return {v.x,v.y};
    }
    else
    {
        return{v.x/s,v.y/s};
    }
}

Vec2 operator*(float s, Vec2 const& v)
{
    return{v.x*s,v.y*s};
}



# endif