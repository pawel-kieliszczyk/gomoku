#include "Application/GameController.hpp"

#include <stdexcept>


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


void GameController::moveBlack(int x, int y)
{
    board->putBlackDot(x, y);
}


void GameController::moveWhite(int x, int y)
{
    throw std::runtime_error("Trying to move when opponent's turn");
}


} // namespace Application
} // namespace Gomoku
