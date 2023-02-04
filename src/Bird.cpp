/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class Bird.
*/

#include <Settings.hpp>
#include <src/Bird.hpp>

Bird::Bird(float _x, float _y, float w, float h) noexcept
    : x{_x}, y{_y}, width{w}, height{h}, vy{0.f}, vx{0.f}, sprite{Settings::textures["bird"]}
{
    sprite.setPosition(x, y);
}

sf::FloatRect Bird::get_collision_rect() const noexcept
{
    return sf::FloatRect{x, y, width, height};
}

void Bird::jump() noexcept
{
    if (!jumping)
    {
        jumping = true;
    }
}


void Bird::der_move() noexcept 
{
  if (!der_mov)
    {
        der_mov = true;
    }

}

void Bird::izq_move() noexcept 
{
  if (!izq_mov)
    {
        izq_mov = true;
    }

}

void Bird::stop_movep() noexcept 
{
     if (!stop_mov)
    {
        stop_mov = true;
    }
}





void Bird::update(float dt) noexcept
{

  if (der_mov)
    {
       
       

        vx = Settings::SPEED_MOV;



    der_mov = false;

        
    }

      if (izq_mov)
    {
    
    
     vx = vy = 0; 


      vx = -Settings::SPEED_MOV_IZQ;



    izq_mov = false;

        
    }


      if (stop_mov)
    {

    
      vx = vy = 0; 


      vx = -Settings::SPEED_REDUCE;


    stop_mov = false;

        
    }








    vy += Settings::GRAVITY * dt;

    if (jumping)
    {
        Settings::sounds["jump"].play();
        vy = -Settings::JUMP_TAKEOFF_SPEED;
        jumping = false;
    }


  
    x += vx * dt;
    y += vy * dt;
    sprite.setPosition(x, y);
}






void Bird::render(sf::RenderTarget& target) const noexcept
{
    target.draw(sprite);
}