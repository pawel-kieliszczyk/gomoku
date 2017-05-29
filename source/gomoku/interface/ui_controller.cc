#include "gomoku/interface/ui_controller.h"

#include <iostream>
#include <memory>

#include "gomoku/application/artificial_intelligence/alpha_beta_player_factory.h"
#include "gomoku/application/artificial_intelligence/mini_max_player_factory.h"
#include "gomoku/application/artificial_intelligence/monte_carlo_tree_search_player_factory.h"
#include "gomoku/application/game_controller_factory.h"
#include "gomoku/domain/board.h"
#include "gomoku/interface/board_drawer.h"
#include "gomoku/interface/human_player_factory.h"


namespace Gomoku
{
namespace Interface
{


void UIController::run()
{
    printGameTitle();

    auto gameMode = readGameMode();

    auto board = std::make_shared<Gomoku::Domain::Board>();

    Gomoku::Interface::BoardDrawer boardDrawer(board);

    auto playerFactory1 = getFirstPlayerFactoryFor(gameMode);
    auto playerFactory2 = getSecondPlayerFactoryFor(gameMode);

    Gomoku::Application::GameControllerFactory gameControllerFactory;
    auto gameController = gameControllerFactory.create(board, playerFactory1, playerFactory2);

    gameController->initializeNewGame();
    gameController->play();
}


void UIController::printGameTitle()
{
    std::cout << std::endl;
    std::cout << "\033[1;33m    _______   ______   .___  ___.   ______    __  ___  __    __ \033[0m" << std::endl;
    std::cout << "\033[1;33m   /  _____| /  __  \\  |   \\/   |  /  __  \\  |  |/  / |  |  |  |\033[0m" << std::endl;
    std::cout << "\033[1;33m  |  |  __  |  |  |  | |  \\  /  | |  |  |  | |  '  /  |  |  |  |\033[0m" << std::endl;
    std::cout << "\033[1;33m  |  | |_ | |  |  |  | |  |\\/|  | |  |  |  | |    <   |  |  |  |\033[0m" << std::endl;
    std::cout << "\033[1;33m  |  |__| | |  `--'  | |  |  |  | |  `--'  | |  .  \\  |  `--'  |\033[0m" << std::endl;
    std::cout << "\033[1;33m   \\______|  \\______/  |__|  |__|  \\______/  |__|\\__\\  \\______/ \033[0m" << std::endl;
    std::cout << std::endl;
}


UIController::GameMode UIController::readGameMode()
{
    std::cout << "Available game modes:" << std::endl;
    std::cout << "1. Player vs Player" << std::endl;
    std::cout << "2. Player (black) vs Artificial Intelligence (white)" << std::endl;
    std::cout << "3. Artificial Intelligence (black) vs Player (white)" << std::endl;
    std::cout << std::endl;

    int gameModeNumber;
    std::cout << "Pick game mode: ";
    std::cin >> gameModeNumber;

    switch(gameModeNumber)
    {
        case 1: return GameMode::PlayerVsPlayer;
        case 2: return GameMode::PlayerVsArtificialIntelligence;
        case 3: return GameMode::ArtificialIntelligenceVsPlayer;
    }

    return GameMode::PlayerVsPlayer;
}


std::shared_ptr<Application::IPlayerFactory> UIController::getFirstPlayerFactoryFor(GameMode gameMode)
{
    if(gameMode == GameMode::ArtificialIntelligenceVsPlayer)
        return std::make_shared<Application::ArtificialIntelligence::AlphaBetaPlayerFactory>();

    return std::make_shared<HumanPlayerFactory>("Player 1");
}


std::shared_ptr<Application::IPlayerFactory> UIController::getSecondPlayerFactoryFor(GameMode gameMode)
{
    if(gameMode == GameMode::PlayerVsArtificialIntelligence)
        return std::make_shared<Application::ArtificialIntelligence::AlphaBetaPlayerFactory>();

    return std::make_shared<HumanPlayerFactory>("Player 2");
}


} // namespace Interface
} // namespace Gomoku
