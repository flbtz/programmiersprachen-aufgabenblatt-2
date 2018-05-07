#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"



class Rectangle{

public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& color);

    Vec2 get_min() const;
    Vec2 get_max() const;
    Color get_color() const;
    float get_length() const;
    float get_height() const;
    float circumference() const;

    void draw(Window const& w);
    void draw(Window const& w, float r,float g,float b);
    bool is_inside(Vec2 const& v);

private:
    Vec2 min_;
    Vec2 max_;
    Color color_;



};

#endif