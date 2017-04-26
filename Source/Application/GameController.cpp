#include "Application/GameController.hpp"

#include <stdexcept>


namespace Gomoku
{
namespace Application
{


GameController::GameController(std::shared_ptr<Domain::IBoard> board_) : board(board_), nextTurn(NextTurn::Black)
{
}


void GameController::startNewGame()
{
    board->clear();
}


void GameController::moveBlack(int x, int y)
{
    if(nextTurn != NextTurn::Black)
        throw std::runtime_error("Trying to move when opponent's turn");

    board->putBlackDot(x, y);
    nextTurn = NextTurn::White;
}


void GameController::moveWhite(int x, int y)
{
    if(nextTurn != NextTurn::White)
        throw std::runtime_error("Trying to move when opponent's turn");

    board->putWhiteDot(x, y);
}


} // namespace Application
} // namespace Gomoku
