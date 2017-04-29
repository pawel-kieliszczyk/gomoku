#include <memory>

#include "Application/GameControllerFactory.hpp"
#include "Domain/Board.hpp"
#include "Interface/BoardDrawer.hpp"
#include "Interface/HumanPlayerFactory.hpp"


int main()
{
    auto board = std::make_shared<Gomoku::Domain::Board>();
    auto playerFactory1 = std::make_shared<Gomoku::Interface::HumanPlayerFactory>("Player 1");
    auto playerFactory2 = std::make_shared<Gomoku::Interface::HumanPlayerFactory>("Player 2");

    Gomoku::Application::GameControllerFactory gameControllerFactory;
    auto gameController = gameControllerFactory.create(board, playerFactory1, playerFactory2);

    Gomoku::Interface::BoardDrawer boardDrawer(board);

    gameController->initializeNewGame();
    gameController->play();
}
