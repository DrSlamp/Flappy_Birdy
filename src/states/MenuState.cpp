#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include "MenuState.hpp"


MenuState::MenuState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}
{

}

void MenuState::handle_inputs(const sf::Event& event) noexcept
{
    if (event.key.code == sf::Keyboard::N)
    {
        state_machine->change_state("title");
    }
     if (event.key.code == sf::Keyboard::H)
    {
        exit();
    }
}

void MenuState::update(float dt) noexcept
{
    world.update(dt);
}

void MenuState::render(sf::RenderTarget& target) const noexcept 
{
    world.render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 1.50 * Settings::VIRTUAL_HEIGHT / 3, "Menu Game", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::Yellow, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 1.75 * Settings::VIRTUAL_HEIGHT / 3, "Normal Mode press N", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, 2.00 * Settings::VIRTUAL_HEIGHT / 3, "Hard Mode press H", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    
}