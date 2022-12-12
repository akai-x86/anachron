#include "vector2.h"
#include <cmath>
#include <cassert>


Vector2::Vector2(float xPos, float yPos) : x(xPos), y(yPos) {};

const Vector2 
   Vector2::ZERO ( 0.0,  0.0),
   Vector2::ONE  ( 1.0,  1.0),
   Vector2::UP   ( 0.0, -1.0),
   Vector2::DOWN ( 0.0,  1.0),
   Vector2::LEFT (-1.0,  0.0),
   Vector2::RIGHT( 1.0,  0.0);


Vector2 Vector2::operator+(const Vector2 &rhs) const
{
   return {x + rhs.x,
           y + rhs.y};
};

Vector2 Vector2::operator+=(const Vector2 &rhs)
{
   this->x += rhs.x;
   this->y += rhs.y;
   return *this;
}

Vector2 Vector2::operator-() const
{
   return {-x, -y};
};

Vector2 Vector2::operator-(const Vector2 &rhs) const
{
   return {x - rhs.x,
           y - rhs.y};
};

Vector2 Vector2::operator*(float scalar) const
{
   return {x*scalar, y*scalar};
};

Vector2 operator*(float scalar, const Vector2 &rhs) 
{
   return {rhs.x*scalar, rhs.y*scalar};
};

float Vector2::GetLength() const 
{
   return std::hypot(x, y);
};

Vector2 Vector2::Normalize() const
{
   float Length = std::hypot(x, y);
   assert(Length > 0);
   return {x / Length, y / Length};
};

float Vector2::GetDistance(const Vector2 &rhs) const
{
   return std::abs(GetLength() - rhs.GetLength());
};

float Vector2::GetX() const 
{
   return x;
}

float Vector2::GetY() const
{
   return y;
}
