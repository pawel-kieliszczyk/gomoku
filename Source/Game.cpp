#include "Game.hpp"

#include "Interface/UIController.hpp"


namespace Gomoku
{


void Game::play()
{
    Interface::UIController ui;
    ui.run();
}


} // namespace Gomoku
