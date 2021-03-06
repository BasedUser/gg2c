// vec2.cpp

class vec2{
  public:
    float x,y;

    vec2(){
        x = 0;
        y = 0;
    }
    vec2(float _x, float _y){
        x = _x;
        y = _y;
    }

    //dot product of 2 vectors
    float operator*(vec2 a){
        return a.x * x + a.y * y;
                }
    float dotProduct(vec2 a, vec2 b){
        return a.x * b.x + a.y * a.y;
    }

    //add vector
    vec2 operator+(vec2 a){
        return vec2(a.x + x, a.y + y);
    }
    void operator+=(vec2 a){
        x += a.x;
        y += a.y;
    }

    //subtract vector
    vec2 operator-(vec2 a){
        return vec2(a.x - x, a.y - y);
    }
    void operator-=(vec2 a){
        x -= a.x;
        y -= a.y;
    }

    //scale vector
    vec2 operator*(float a){
        return vec2(x * a, y * a);
    }
    void operator*=(float a){
        x *= a, y *= a;
    }
};
