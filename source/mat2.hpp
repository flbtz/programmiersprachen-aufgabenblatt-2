#ifndef MAT2_HPP
#define MAT2_HPP

#include "vec2.hpp"

struct Mat2
{
public:

    Mat2();
    Mat2(Vec2 const& a,Vec2 const& b);


    Mat2 & operator *=( Mat2 const & m );

    float det () const ;

    Vec2 a;
    Vec2 b;


};
Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 );

Vec2 operator *( Mat2 const & m , Vec2 const & v );
Vec2 operator *( Vec2 const & v , Mat2 const & m );
Mat2 inverse ( Mat2 const & m );
Mat2 transpose ( Mat2 const & m );
Mat2 make_rotation_mat2 ( float phi );

#endif