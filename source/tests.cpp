#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

TEST_CASE ( "describe_Vec2" ,"[Vec2]")
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