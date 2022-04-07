#include "World.hpp"
#include "Game.hpp"

World::World() {
    // Create the ground body
    b2BodyDef groundBodyDef;
    b2Vec2 world_position = Game::screen2world(b2Vec2(0, Game::SCREEN_HEIGHT));
    groundBodyDef.position.Set(world_position.x, world_position.y);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
}


void World::update(float elapsedTime) {
    world->Step(elapsedTime, velocityIterations, positionIterations);
}
