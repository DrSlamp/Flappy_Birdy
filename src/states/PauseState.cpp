#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PauseState.hpp>




PauseState::PauseState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}
{

}




void PauseState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) noexcept
{
    world = _world;
    world->reset(false);
    bird = _bird;

    
  
  
  
  

 
}




void PauseState::handle_inputs(const sf::Event& event) noexcept
{




if (event.key.code == sf::Keyboard::P)
    {
      
      
              
                state_machine->change_state("playing", world, bird );
        }
       
}


void PauseState::update(float dt) noexcept
{



bird->update(!dt);
   

 if (world->collides(bird->get_collision_rect()))
    {
        
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        state_machine->change_state("count_down");
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
         
   
        
        ++score;

        Settings::sounds["score"].play();
    }



 
   world->update(!dt);



}







void PauseState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "♫ Game Paused ♫ " + std::to_string(score) , Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::Blue);
     
}

