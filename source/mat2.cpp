#ifndef MAT2_CPP
#define MAT2_CPP

#include"Mat2.hpp"
#include"Vec2.hpp"
#include <math.h>

Mat2::Mat2() : firstRow_(Vec2{ 1.0f, 0.0f }), secondRow_(Vec2{ 0.0f, 1.0f }) {};

Mat2::Mat2(Vec2 const& firstRow, Vec2 const& secondRow): firstRow_(firstRow), secondRow_(secondRow) {}

Mat2& Mat2::operator*=(Mat2 const& m) {
    Vec2 newFirstRow_ = { firstRow_.x * m.firstRow_.x + secondRow_.x * m.firstRow_.y, firstRow_.y * m.firstRow_.x + secondRow_.y * m.firstRow_.y};
    Vec2 newSecondRow_ = {firstRow_.x * m.secondRow_.x + secondRow_.x * m.secondRow_.y, firstRow_.y * m.secondRow_.x + secondRow_.y * m.secondRow_.y};
    firstRow_ = newFirstRow_;
    secondRow_ = newSecondRow_;
    return *this;
};

float Mat2::det() const {
    return firstRow_.x * secondRow_.y - firstRow_.y * secondRow_.x;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
    return Mat2{
            { m1.firstRow_.x * m2.firstRow_.x + m1.secondRow_.x * m2.firstRow_.y, m1.firstRow_.y * m2.firstRow_.x + m1.secondRow_.y * m2.firstRow_.y },
            { m1.firstRow_.x * m2.secondRow_.x + m1.secondRow_.x * m2.secondRow_.y, m1.firstRow_.y * m2.secondRow_.x + m1.secondRow_.y * m2.secondRow_.y }
    };
}

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
    return { m.firstRow_.x * v.x + m.secondRow_.x * v.y, m.firstRow_.y * v.x + m.secondRow_.y * v.y };
};

Vec2 operator*(Vec2 const& v, Mat2 const& m) {
    return { m.firstRow_.x * v.x + m.secondRow_.x * v.y, m.firstRow_.y * v.x + m.secondRow_.y * v.y };
}

Mat2 inverse(Mat2 const& m) {
    float a = m.firstRow_.x * m.secondRow_.y - m.secondRow_.x * m.firstRow_.y;
    return { { m.secondRow_.y / a , - m.firstRow_.y / a} , { - m.secondRow_.x / a , m.firstRow_.x / a } };
}

Mat2 transpose(Mat2 const& m) {
    return { {m.firstRow_.x,m.secondRow_.x},{m.firstRow_.y,m.secondRow_.y} };
}

Mat2 make_rotation_mat2(float phi) {
    return { { (float)cos(phi), (float)sin(phi)}, { (float)-sin(phi) , (float)cos(phi)} };
}

#endif