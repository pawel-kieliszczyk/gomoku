#include "game.h"

#include "gomoku/interface/ui_controller.h"


namespace Gomoku
{


void Game::play()
{
    Interface::UIController ui;
    ui.run();
}


} // namespace Gomoku
