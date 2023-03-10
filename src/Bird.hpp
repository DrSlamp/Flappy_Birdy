/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class Bird.
*/

#pragma once

#include <SFML/Graphics.hpp>

class Bird
{
public:
    Bird(float _x, float _y, float w, float h) noexcept;

    Bird(const Bird&) = delete;

    Bird& operator = (Bird) = delete;

    sf::FloatRect get_collision_rect() const noexcept;

    void jump() noexcept;

    void der_move() noexcept;

    void izq_move() noexcept;

    void stop_movep() noexcept;

    void update(float dt) noexcept;

    void render(sf::RenderTarget& target) const noexcept;

private:
    float x;
    float y;
    float width;
    float height;
    float vy;
    float vx;
    sf::Sprite sprite;
    bool jumping{false};
    bool der_mov{false};
    bool izq_mov{false};
    bool stop_mov{false};  
};
