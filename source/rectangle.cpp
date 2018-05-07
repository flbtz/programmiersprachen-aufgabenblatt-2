#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#define _USE_MATH_DEFINES

#include <math.h>
#include "vec2.hpp"
#include "rectangle.hpp"
#include "color.hpp"



Rectangle::Rectangle():
        min_{0.0f,0.0f},
        max_{0.0f,0.0f},
        color_{0.0f}
{};

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& color):
        min_{min},
        max_{max},
        color_{color}
{};

Vec2 Rectangle::get_min() const{
    return min_;
}

Vec2 Rectangle::get_max() const{
    return max_;
}

Color Rectangle::get_color() const{
    return color_;
}

float Rectangle::get_length() const{
    return max_.x-min_.x;
}

float Rectangle::get_height() const{
    return max_.y-min_.y;
}

float Rectangle::circumference() const{
    return 2*get_length()+2*get_height();
}


void Rectangle::draw(Window const& w)
{
    Color c = get_color();
    w.draw_line(get_min().x,get_min().y,get_min().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_min().x,get_max().y,get_max().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_max().y,get_max().x,get_min().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_min().y,get_min().x,get_min().y,c.r_,c.g_,c.b_);

}

void Rectangle::draw(Window const& w, float r,float g,float b)
{
    Color c = {r,g,b};
    w.draw_line(get_min().x,get_min().y,get_min().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_min().x,get_max().y,get_max().x,get_max().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_max().y,get_max().x,get_min().y,c.r_,c.g_,c.b_);
    w.draw_line(get_max().x,get_min().y,get_min().x,get_min().y,c.r_,c.g_,c.b_);

}



bool Rectangle::is_inside(Vec2 const& v){
    if(v.x > min_.x && v.x < max_.x && v.y > min_.y && v.y < max_.y){
        return true;
    }
    else{
        return false;
    }
}


#endif