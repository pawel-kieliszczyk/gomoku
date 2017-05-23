#include "Game.hpp"

#include "interface/UIController.hpp"


namespace Gomoku
{


void Game::play()
{
    Interface::UIController ui;
    ui.run();
}


} // namespace Gomoku
