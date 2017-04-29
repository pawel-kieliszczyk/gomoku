#include "Interface/BoardDrawer.hpp"

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
    std::cout << "                         1 1 1 1 1" << std::endl;
    std::cout << "     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << std::endl;

    std::cout << "   ,-";
    for(int i = 0; i < board->getSize(); ++i)
        std::cout << "--";
    std::cout << "," << std::endl;

    for(int i = 0; i < board->getSize(); ++i)
    {
        if(i < 10)
            std::cout << " ";
        std::cout << i << " | ";

        for(int j = 0; j < board->getSize(); ++j)
        {
            if(!board->hasStone(i, j))
            {
                std::cout << "  ";
                continue;
            }

            const auto stone = board->getStone(i, j);
            if(stone == Domain::Stone::Black)
                std::cout << "x ";
            else
                std::cout << "o ";
        }
        std::cout << "|" << std::endl;
    }

    std::cout << "   '-";
    for(int i = 0; i < board->getSize(); ++i)
        std::cout << "--";
    std::cout << "'" << std::endl;
}


} // namespace Interface
} // namespace Gomoku
