#include "Frog.hpp"
#include "World.hpp"
#include "Game.hpp"

#include <SDL.h>
#include <SDL_image.h>


Frog::Frog(const b2Vec2& position, const World& world)
{
    // Create a dynamic body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(position.x, position.y);
    _body = world.getWorld()->CreateBody(&bodyDef);

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
    _body->CreateFixture(&fixtureDef);
}

void Frog::impulse() {
    _body->ApplyForce(b2Vec2(0,100.0), _body->GetPosition(), true);
}

void Frog::render(SDL_Renderer *renderer, float color) {
    b2Vec2 frog_world_position = getPosition();
    b2Vec2 frog_screen_position = Game::world2screen(frog_world_position);
    //Render filled quad
    SDL_Rect fillRect = { static_cast<int>(frog_screen_position.x),
                          static_cast<int>(frog_screen_position.y),
                          Game::SCREEN_WIDTH/20, Game::SCREEN_WIDTH/20 };
    SDL_SetRenderDrawColor(renderer, 200, color, 0, 255);
    SDL_RenderFillRect( renderer, &fillRect );
}

void Frog::update(float delta) {
    _timeAlive += delta;
}
