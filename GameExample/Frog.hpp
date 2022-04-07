#ifndef Frog_hpp
#define Frog_hpp

#include <memory>
#include <stdio.h>
#include <box2d/box2d.h>

class World;

class Frog {

public:
    Frog(const b2Vec2& position, const World& world);
    Frog(const Frog&);
    Frog& operator=(const Frog&);
    void update(float delta);
    void impulse();
    b2Vec2 getPosition() const {return _body->GetPosition();};
    const b2Body* getBody() {return _body;};
private:
    const int SPEED {5};
    float _timeAlive {0};
    b2Body* _body;
};

#endif /* Frog_hpp */
