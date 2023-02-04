/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Log.
*/

#include <Settings.hpp>
#include <src/Log.hpp>

Log::Log(float _x, float _y, bool _inverted) noexcept
    : x{_x}, y{_y}, vy{}, inverted{_inverted}, sprite{Settings::textures["Log"]}
{
    if (inverted)
    {
        sprite.rotate(180.f);
    }
}

sf::FloatRect Log::get_collision_rect() const noexcept
{
    if (!inverted)
    {
        return sf::FloatRect{x, y, Settings::LOG_WIDTH, Settings::LOG_HEIGHT};
    }

    return sf::FloatRect{x - Settings::LOG_WIDTH, y - Settings::LOG_HEIGHT, Settings::LOG_WIDTH, Settings::LOG_HEIGHT};
}

void Log::update(float _x) noexcept
{
    x = _x;

    if (inverted)
    {
        x += Settings::LOG_WIDTH;
    }

    sprite.setPosition(x, y);
}


void Log::update_log(float dt) noexcept
{
vx = vy = 0; 

 if (inverted)
    {
        vy += Settings::SPEED_REDUCE;
    }
    else {
            vy += -Settings::SPEED_REDUCE;

    }




    y += vy * dt;
    // set the absolute position of the entity
sprite.setPosition(0.f, 238.f);

// move the entity relatively to its current position
sprite.move(0.f, 50.f);

// retrieve the absolute position of the entity
sf::Vector2f position = sprite.getPosition(); // = (15, 55)



  //  sprite.setPosition(x, y);
}



void Log::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}
