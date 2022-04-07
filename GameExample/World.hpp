#ifndef World_hpp
#define World_hpp

#include <stdio.h>
#include <memory>
#include <box2d/box2d.h>


class World {

const int32 velocityIterations {6};
const int32 positionIterations {2};

public:

    World();
    ~World() = default;
    void update(float elapsedTime);
    const b2Vec2 gravity{0.0f, -10.0f};
    std::unique_ptr<b2World> world{std::make_unique<b2World>(gravity)};

};

#endif /* World_hpp */
