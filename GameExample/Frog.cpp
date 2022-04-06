#include "Frog.hpp"

Frog::Frog(const b2Vec2& position, const std::unique_ptr<b2World>& world) {
    this->position = position;

    // Create a dynamic body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    body = world->CreateBody(&bodyDef);

    // Next we create a fixture definition using the box. Notice that we set density to 1.
    // The default density is zero. Also, the friction on the shape is set to 0.3.
    b2FixtureDef fixtureDef;
    // create and attach a polygon shape using a fixture definition. First we create a box shape:
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(0.1f, 0.1f);
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 10.0f;
    fixtureDef.friction = 0.01f;
    // Using the fixture definition we can now create the fixture. This automatically updates the mass of the body.
    // You can add as many fixtures as you like to a body. Each one contributes to the total mass.
    this->body->CreateFixture(&fixtureDef);
}

void Frog::impulse() {
    body->ApplyForce(b2Vec2(0,100.0), body->GetPosition(), true);
}

// Update object position to match with the Box2D body.
void Frog::update(float delta, const b2Body* body) {
    position.x = body->GetPosition().x;
    position.y = body->GetPosition().y;
    timeAlive += delta;
}

b2Vec2 Frog::getPosition() {
    return body->GetPosition();
}
