#include "application/game_controller.h"

#include <stdexcept>


namespace Gomoku
{
namespace Application
{


GameController::GameController(
        std::shared_ptr<Domain::IBoard> board_,
        std::shared_ptr<IPlayerFactory> playerFactory1_,
        std::shared_ptr<IPlayerFactory> playerFactory2_,
        std::shared_ptr<IGameFinishedPolicyFactory> gameFinishedPolicyFactory_)
    : board(board_),
      playerFactory1(playerFactory1_),
      playerFactory2(playerFactory2_),
      gameFinishedPolicyFactory(gameFinishedPolicyFactory_)
{
}


void GameController::initializeNewGame()
{
    board->clear();

    playerBlack = playerFactory1->create(board, Domain::Stone::Black);
    playerWhite = playerFactory2->create(board, Domain::Stone::White);

    gameFinishedPolicy = gameFinishedPolicyFactory->create(board);
}


void GameController::play()
{
    while(true)
    {
        playerBlack->performMove();
        if(gameFinishedPolicy->isFinished())
            break;

        playerWhite->performMove();
        if(gameFinishedPolicy->isFinished())
            break;
    }
}


} // namespace Application
} // namespace Gomoku
