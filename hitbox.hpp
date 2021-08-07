// hitbox.cpp

#include "meta/vec2.hpp"
class rect{
  public:
    vec2 pos,size; //position and size of rect

    rect(vec2 _pos, vec2 _size){
        pos = _pos;
        size = _size;
    }
};

class hitbox{
  public:
    rect boundary;
    vec2 midpoint;
    float radiusS; //length from midpoint to corner (squared to avoid complex computation)

    hitbox(rect a){
        boundary = a;
        midpoint = boundary.size * 0.5 + boundary.pos;
        radiusS = 0.25*(boundary.size * boundary.size);
    }
    bool collisionCircle(hitbox h){
    	vec2 distance = h.midpoint - midpoint; //vector distance between the midpoints
        float directDistance = distance * distance; //dotproduct returns the square scalar distance between the midpoints
        return directDistance < radiusS + h.radiusS;
    }
    bool collisionPoint(vec2 pos){
        return (boundary.pos.x < pos.x) && (boundary.pos.x + boundary.size.x > pos.x) && (boundary.pos.y < pos.y) && (boundary.pos.y + boundary.size.y > pos.y);
    }
    bool operator*(hitbox h){ //collidesWith
        if(collisionCircle(h)){
            return (boundary.pos.x + boundary.size.x < h.boundary.pos.x ||
                    h.boundary.pos.x + h.boundary.size.x < boundary.pos.x ||
                    boundary.pos.y + boundary.size.y < h.boundary.pos.y ||
                    h.boundary.pos.y + h.boundary.size.y < boundary.pos.y); // stackoverflow wizardry oh noooooo (you are a wizard harry)
        }
        return false;
    }
};
