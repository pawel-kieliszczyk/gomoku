#include "interface/HumanPlayer.hpp"

#include <iostream>


namespace Gomoku
{
namespace Interface
{


HumanPlayer::HumanPlayer(
        const std::string& name_,
        std::shared_ptr<Domain::IBoard> board_,
        const Domain::Stone& stone_)
    : name(name_),
      board(board_),
      stone(stone_)
{
}


void HumanPlayer::performMove()
{
    std::cout << name << " moving!" << std::endl;

    int x = readX();
    int y = readY();

    while(!validMove(x, y))
    {
        std::cout << "Move impossible!" << std::endl;

        x = readX();
        y = readY();
    }

    board->putStone(x, y, stone);
}


int HumanPlayer::readX()
{
    int x;

    std::cout << "Select row: ";
    std::cin >> x;

    return x;
}


int HumanPlayer::readY()
{
    int y;

    std::cout << "Select column: ";
    std::cin >> y;

    return y;
}


bool HumanPlayer::validMove(int x, int y)
{
    if(x < 0)
        return false;

    if(x >= board->getSize())
        return false;

    if(y < 0)
        return false;

    if(y >= board->getSize())
        return false;

    if(board->hasStone(x, y))
        return false;

    return true;
}


} // namespace Interface
} // namespace Gomoku
