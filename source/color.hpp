#ifndef COLOR_HPP
#define COLOR_HPP

#include<iostream>

struct Color
{

    Color(float input)
    {
        if( input <=1.0f && input >= 0.0f){
            r_= input ;
            g_= input ;
            b_= input ;
        }
        else
        {
            r_= 0.0f;
            g_= 0.0f;
            b_= 0.0f;
            std::cout << "Farbe existiert nicht, Standardfarbe ist schwarz.";
        }
    };

    Color (float r, float g, float b){
        if(r>=0.0f && r<=1.0f && g>=0.0f && g<=1.0f && b>=0.0f && b<=1.0f){
            r_=r;
            g_=g;
            b_=b;
        }
        else
        {
            r_=0.0f;
            g_=0.0f;
            b_=0.0f;
            std::cout << "Farbe existiert nicht, Standardfarbe ist schwarz.";
        }
    };

    float r_;
    float g_;
    float b_;
};
#endif