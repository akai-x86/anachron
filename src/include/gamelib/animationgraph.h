#pragma once
#include <vector>
#include <memory>
#include <optional>
#include <hash_map>
#include <hash_set>

class Animation
{

};

enum LinkDirection
{
   Left,
   Right,
   Both,
   None
};

class AnimationLink
{
   AnimationLink(Animation a, Animation b, LinkDirection direction);

   friend
   AnimationLink operator> (Animation a, Animation b),
                 operator< (Animation a, Animation b),
                 operator- (Animation a, Animation b),
                 operator* (Animation a, Animation b);


};

class AnimationGraph
{
   public:
      void Travel();

      AnimationGraph Add(),
                     Connect();


   private:
      std::vector<Animation> vertices;
      std::vector<std::tuple<Animation, Animation>> edges;

};


