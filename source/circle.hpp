#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle{

public:
    Circle();
    Circle(float radius, Vec2 const& mp, Color const& color);

    float get_radius() const;
    Vec2 get_mp() const;
    Color get_color() const;
    float circumference() const;

    void draw(Window const& window);
    void draw(Window const& window, float r, float g, float b);

    bool is_inside(Vec2 const& v);

private:

    float radius_;
    Vec2 mp_;
    Color color_;
};

#endif