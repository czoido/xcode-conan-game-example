#ifndef Frog_hpp
#define Frog_hpp

#include <memory>
#include <stdio.h>
#include <box2d/box2d.h>

class Frog {

public:
    Frog(const b2Vec2& position, const std::unique_ptr<b2World>& world);
    Frog(const Frog&);
    Frog& operator=(const Frog&);
    void update(float delta, const b2Body* body);
    b2Vec2 getPosition();
    void impulse();
    const b2Body* getBody() {return body;};
private:
    const int SPEED = 5;
    b2Vec2 position;
    float timeAlive;
    b2Body* body;
};

#endif /* Frog_hpp */
