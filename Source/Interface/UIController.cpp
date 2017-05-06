#include "Interface/UIController.hpp"

#include <iostream>
#include <memory>

#include "Application/GameControllerFactory.hpp"
#include "Application/ArtificialIntelligence/AlphaBetaPlayerFactory.hpp"
#include "Application/ArtificialIntelligence/MiniMaxPlayerFactory.hpp"
#include "Domain/Board.hpp"
#include "Interface/BoardDrawer.hpp"
#include "Interface/HumanPlayerFactory.hpp"


namespace Gomoku
{
namespace Interface
{


void UIController::run()
{
    printGameTitle();

    auto gameMode = readGameMode();

    auto board = std::make_shared<Gomoku::Domain::Board>();

    auto playerFactory1 = getFirstPlayerFactoryFor(gameMode);
    auto playerFactory2 = getSecondPlayerFactoryFor(gameMode);

    Gomoku::Application::GameControllerFactory gameControllerFactory;
    auto gameController = gameControllerFactory.create(board, playerFactory1, playerFactory2);

    Gomoku::Interface::BoardDrawer boardDrawer(board);

    gameController->initializeNewGame();
    gameController->play();
}


void UIController::printGameTitle()
{
    std::cout << std::endl;
    std::cout << R"(    _______   ______   .___  ___.   ______    __  ___  __    __ )" << std::endl;
    std::cout << R"(   /  _____| /  __  \  |   \/   |  /  __  \  |  |/  / |  |  |  |)" << std::endl;
    std::cout << R"(  |  |  __  |  |  |  | |  \  /  | |  |  |  | |  '  /  |  |  |  |)" << std::endl;
    std::cout << R"(  |  | |_ | |  |  |  | |  |\/|  | |  |  |  | |    <   |  |  |  |)" << std::endl;
    std::cout << R"(  |  |__| | |  `--'  | |  |  |  | |  `--'  | |  .  \  |  `--'  |)" << std::endl;
    std::cout << R"(   \______|  \______/  |__|  |__|  \______/  |__|\__\  \______/ )" << std::endl;
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
