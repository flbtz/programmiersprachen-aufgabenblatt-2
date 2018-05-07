#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "circle.hpp"



int main(int argc, char *argv[])
{
    return Catch::Session().run(argc, argv);
}


TEST_CASE ( " describe_Vec2" ,"[Vec2]")
{
    Vec2 v1 = Vec2{};
    Vec2 v2 = Vec2{2.4f,3.5f};
    Vec2 v3 = Vec2{10.0f,4.0f};

    SECTION("test_default_constructor"){

        REQUIRE (v1.x ==0.0f);
        REQUIRE (v1.y ==0.0f);
    }
    SECTION("test_parameter_constructor"){

        REQUIRE (v2.x ==2.4f);
        REQUIRE (v2.y ==3.5f);

    }
    SECTION("test_operator+="){


        v1 +=v2;
        v2 +=v3;

        REQUIRE (v1.x == 2.4f);
        REQUIRE (v1.y == 3.5f);
        REQUIRE (v2.x == 12.4f);
        REQUIRE (v2.y == 7.5f);


    }

    SECTION("test_operator-="){

        v1 -=v2;
        v2 -=v3;

        REQUIRE (v1.x == -2.4f);
        REQUIRE (v1.y == -3.5f);
        REQUIRE (v2.x == -7.6f);
        REQUIRE (v2.y == -0.5f);


    }

    SECTION("test_operator*="){
        v1 *= 5.0f;
        v3 *= 5.0f;

        REQUIRE (v1.x == 0.0f);
        REQUIRE (v1.y == 0.0f);
        REQUIRE (v3.x == 50.0f);
        REQUIRE (v3.y == 20.0f);


    }
    SECTION("test_operator/="){
        v1 /= 5.0f;
        v3 /= 2.0f;

        REQUIRE (v1.x == 0.0f);
        REQUIRE (v1.y == 0.0f);
        REQUIRE (v3.x == 5.0f);
        REQUIRE (v3.y == 2.0f);


    }

    SECTION("test_operator+")
    {
        Vec2 s1 = {5.5f,6.0f};
        Vec2 s2 = {1.4f,4.6f};
        Vec2 sum1 = s1+s2;

        REQUIRE (sum1.x ==6.9f);
        REQUIRE (sum1.y ==10.6f);
    }

    SECTION("test_operator-"){

        Vec2 d1 = {5.5f,0.0f};
        Vec2 d2 = {1.4f,4.4f};
        Vec2 subtr1 = d1-d2;


        REQUIRE (subtr1.y ==-4.4f);
        REQUIRE (subtr1.x ==4.1f);

    }

    SECTION("test_operator*(1)"){

        Vec2 f1 = {5.5f,6.0f};
        float f2 = {3.0f};
        Vec2 prd1 = f1*f2;

        REQUIRE (prd1.x ==16.5f);
        REQUIRE (prd1.y ==18.0f);
    }


    SECTION("test_operator/"){

        Vec2 div1 = {12.0f,6.0f};
        float div2 = {3.0f};
        Vec2 erg1 = div1/div2;
        Vec2 div3 = {10.0f,1.0f};
        float div4 = {0.0f};
        Vec2 erg2 = div3/div4;

        REQUIRE (erg1.x ==4.0f);
        REQUIRE (erg1.y ==2.0f);
        REQUIRE (erg2.x ==10.0f);
        REQUIRE (erg2.y ==1.0f);
    }

    SECTION("test_operator*(2)"){

        Vec2 f2 = {5.5f,6.0f};
        float f1 = {3.0f};
        Vec2 prd2 = f1*f2;

        REQUIRE (prd2.x ==16.5f);
        REQUIRE (prd2.y ==18.0f);
    }

}

TEST_CASE (" describe_Mat2", "[Mat2]") {
Mat2 matrix1 = {};
Mat2 matrix2 = {{3.0f,2.0f},{6.0f,1.0f}};
Mat2 matrix3 = {{-2.0f,3.0f},{1.0f,5.0f}};
Vec2 vektor1 = {2.0f,4.0f};


SECTION("test_operator*="){
matrix1*=matrix3;

REQUIRE(matrix1.a.x == -2.0f);
REQUIRE(matrix1.a.y == 3.0f);
REQUIRE(matrix1.b.x == 1.0f);
REQUIRE(matrix1.b.y == 5.0f);

}

SECTION("test_operator*_matrix"){
Mat2 matrix4 = matrix1*matrix2;

REQUIRE(matrix4.a.x == 3.0f);
REQUIRE(matrix4.a.y == 2.0f);
REQUIRE(matrix4.b.x == 6.0f);
REQUIRE(matrix4.b.y == 1.0f);

}

SECTION("test_operator*_vector"){
Vec2 vektor2 = matrix3*vektor1;

REQUIRE(vektor2.x == 0.0f);
REQUIRE(vektor2.y == 26.0f);
}

SECTION("test_determinant"){
REQUIRE(matrix2.det() == -9.0f);
REQUIRE(matrix1.det() == 1.0f);
}

SECTION("test_inverse"){
Mat2 matrix5 = inverse(matrix1);

REQUIRE(matrix5.a.x == 1.0f);
REQUIRE(matrix5.a.y == 0.0f);
REQUIRE(matrix5.b.x == 0.0f);
REQUIRE(matrix5.b.y == 1.0f);
}

SECTION("test_transposion"){
Mat2 matrix6 = make_rotation_mat2((float)M_PI_4);

REQUIRE(matrix6.a.x == Approx(0.70711f));
REQUIRE(matrix6.a.y == Approx(0.70711f));
REQUIRE(matrix6.b.x == Approx(-0.70711f));
REQUIRE(matrix6.b.y == Approx(0.70711f));

}
}

TEST_CASE ("TEst_Case_2.8_color", "[Task_2.8_color]")
{
    Color black{0.0f};
    Color blue{0.0f,0.0f,1.0f};

    SECTION("default_constuctor")
    {
        REQUIRE(black.r_ == 0.0f);
        REQUIRE(black.g_ == 0.0f);
        REQUIRE(black.b_ == 0.0f);
    }

    SECTION("constuctor")
    {
        REQUIRE(blue.r_ == 0.0f);
        REQUIRE(blue.g_ == 0.0f);
        //REQUIRE(blue.b_ == 0.0f);
        REQUIRE(blue.b_ == 1.0f);
    }

}

TEST_CASE ("Test_case_2.8_circle", "[Task 2.8_circle]"){

    Circle c1{};
    Circle c2{2.0f,{3.0f,1.0f},1.0f};

    SECTION("test_constr")
    {
        REQUIRE(c2.get_radius() == 2.0f);
        REQUIRE(c2.get_mp().x == 3.0f);
        REQUIRE(c2.get_mp().y == 1.0f);
    }
    SECTION("test_default_Constr")
    {
        REQUIRE(c1.get_radius() == 0.0f);
        REQUIRE(c1.get_mp().x == 0.0f);
        REQUIRE(c1.get_mp().y == 0.0f);
    }

    SECTION("test_circumference")
    {
        REQUIRE(c2.circumference() == Approx(12.5664f));
    }

    SECTION("test_is_inside")
    {
        REQUIRE(!c2.is_inside({1.0f,0.0f}));
        REQUIRE(c2.is_inside({3.0f,1.0f}));
    }

}