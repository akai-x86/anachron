#pragma once

class Vector2
{
public:
   Vector2  
      (float xPos, float yPos);

   [[nodiscard]] float    
      Cross      (const Vector2 &rhs) const,
      GetDistance(const Vector2 &rhs) const,
      GetLength  () const,
      GetX       () const,
      GetY       () const;


   [[nodiscard]] Vector2
      Dot        (const Vector2 &rhs) const,
      Rotate     (float angle) const,
      Normalize  () const;
   
   Vector2    
      operator+  (const Vector2 &rhs) const,
      operator-  () const,
      operator-  (const Vector2 &rhs) const,
      operator*  (float scalar) const,
      operator+= (const Vector2 &rhs),
      operator== (const Vector2 &rhs) const,
      operator!= (const Vector2 &rhs) const;


   friend Vector2
      operator*  (float scalar, const Vector2 &rhs);
 
   static const Vector2 
      ZERO, 
      ONE, 
      UP, 
      DOWN, 
      LEFT, 
      RIGHT;


private:
   float
      x,
      y;
};

