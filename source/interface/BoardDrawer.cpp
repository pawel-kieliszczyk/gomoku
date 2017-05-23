#include "interface/BoardDrawer.hpp"

#include <iostream>


namespace Gomoku
{
namespace Interface
{


BoardDrawer::BoardDrawer(std::shared_ptr<Domain::IBoard> board_) : board(board_)
{
    board->addObserver(*this);
}

void BoardDrawer::onStonePutAt(int x, int y)
{
    drawCurrentBoard(x, y);
}


void BoardDrawer::onBoardCleared()
{
    drawCurrentBoard(-1, -1);
}


void BoardDrawer::drawCurrentBoard(const int lastMoveX, const int lastMoveY)
{
    std::cout << colorNumbers() << "                         1 1 1 1 1" << std::endl;
    std::cout << colorNumbers() << "     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << std::endl;

    std::cout << colorBoard() << "   ,-";
    for(int i = 0; i < board->getSize(); ++i)
        std::cout << "--";
    std::cout << "," << colorDefault() << std::endl;

    for(int i = 0; i < board->getSize(); ++i)
    {
        if(i < 10)
            std::cout << " ";
        std::cout << colorNumbers() << i << colorBoard() << " | ";

        for(int j = 0; j < board->getSize(); ++j)
        {
            if(!board->hasStone(i, j))
            {
                std::cout << "  ";
                continue;
            }

            const auto stone = board->getStone(i, j);
            if(stone == Domain::Stone::Black)
            {
                if((i == lastMoveX) && (j == lastMoveY))
                    std::cout << colorLastMoveBlackStone() << "x " << colorDefault();
                else
                    std::cout << colorBlackStone() << "x ";
            }
            else
            {
                if((i == lastMoveX) && (j == lastMoveY))
                    std::cout << colorLastMoveWhiteStone() << "o " << colorDefault();
                else
                    std::cout << colorWhiteStone() << "o ";
            }
        }
        std::cout << colorBoard() << "|" << std::endl;
    }

    std::cout << colorBoard() << "   '-";
    for(int i = 0; i < board->getSize(); ++i)
        std::cout << "--";
    std::cout << "'" << colorDefault() << std::endl;
}


std::string BoardDrawer::colorNumbers() const
{
    return "\033[34m";
}


std::string BoardDrawer::colorBoard() const
{
    return "\033[32m";
}


std::string BoardDrawer::colorBlackStone() const
{
    return "\033[31m";
}


std::string BoardDrawer::colorWhiteStone() const
{
    return "\033[36m";
}


std::string BoardDrawer::colorLastMoveBlackStone() const
{
    return "\033[1;31m";
}


std::string BoardDrawer::colorLastMoveWhiteStone() const
{
    return "\033[1;36m";
}


std::string BoardDrawer::colorDefault() const
{
    return "\033[0m";
}


} // namespace Interface
} // namespace Gomoku
