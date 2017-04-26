#include "Application/GameController.hpp"


namespace Gomoku
{
namespace Application
{


GameController::GameController(std::shared_ptr<Domain::IBoard> board_) : board(board_)
{
}


void GameController::startNewGame()
{
    board->clear();
}


} // namespace Application
} // namespace Gomoku
