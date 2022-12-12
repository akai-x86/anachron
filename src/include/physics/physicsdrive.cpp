#include "physicsdrive.h"

void PhysicsDrive::AddForce(Vector2 force) 
{
   this->frameVelocity_ += force;
};

void PhysicsDrive::AddForce(float amount, Vector2 axis) 
{
   this->frameVelocity_ += (amount * axis);
};

