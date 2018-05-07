#ifndef CIRCLE_CPP
#define CIRCLE_CPP
#define _USE_MATH_DEFINES

#include <cmath>
#include"vec2.hpp"
#include "circle.hpp"
#include "color.hpp"


Circle::Circle():
        radius_{0.0f},
        mp_{0.0f,0.0f},
        color_{0.0f}
{};

Circle::Circle (float radius, Vec2 const & mp, Color const& color):
        radius_{radius},
        mp_{mp},
        color_{color}
{};

float Circle::get_radius() const{
    return radius_;
}

Vec2 Circle::get_mp() const{
    return mp_;
}

Color Circle::get_color() const{
    return color_;
}

float Circle::circumference() const{
    return 2*M_PI*get_radius();
}

void Circle::draw(Window const& window) {
    Vec2 start{};
    Vec2 end{};
    Color c{0.0f};
    c = get_color();

    for (int i = 0; i<=360; i++){
        start = {(float)sin((2*M_PI*i)/360)*get_radius()+mp_.x,(float)cos((2*M_PI*i)/360)*get_radius()+mp_.y};
        end = {(float)sin(((i+1)*2*M_PI)/360)*get_radius()+mp_.x,(float)cos(((i+1)*2*M_PI)/360)*get_radius()+mp_.y};
        window.draw_line(start.x,start.y,end.x,end.y,c.r_,c.g_,c.b_);
    }
}

void Circle::draw(Window const& window, float r, float g, float b) {
    Vec2 start{};
    Vec2 end{};
    Color c{r,g,b};

    for (int i = 0; i<=360; i++){
        start = {(float)sin((2*M_PI*i)/360)*get_radius()+mp_.x,(float)cos((2*M_PI*i)/360)*get_radius()+mp_.y};
        end = {(float)sin(((i+1)*2*M_PI)/360)*get_radius()+mp_.x,(float)cos(((i+1)*2*M_PI)/360)*get_radius()+mp_.y};
        window.draw_line(start.x,start.y,end.x,end.y,c.r_,c.g_,c.b_);
    }
}

bool Circle::is_inside(Vec2 const& v){
    Vec2 dif = v-get_mp();
    if(sqrt(pow(dif.x,2)+pow(dif.y,2)) <= get_radius()){
        return true;
    }
    else{
        return false;
    }

};

#endif