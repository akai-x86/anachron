#pragma once
#include "../math/vector2.h"

class PhysicsProperty
{
public:
   float 
      GetFriction(),
      GetDrag();

private:
   float 
      friction,
      drag; 
};

class PhysicsDrive 
{
public:
   void 
      AddForce(Vector2 force),
      AddForce(float amount, Vector2 axis); 

private:
   PhysicsProperty physicsProperty_;
   Vector2 frameVelocity_;
};


