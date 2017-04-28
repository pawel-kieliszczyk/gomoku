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
    std::cout << ",-";
    for(int i = 0; i < board->getSize(); ++i)
        std::cout << "--";
    std::cout << "," << std::endl;

    for(int i = 0; i < board->getSize(); ++i)
    {
        std::cout << "| ";

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

    std::cout << "'-";
    for(int i = 0; i < board->getSize(); ++i)
        std::cout << "--";
    std::cout << "'" << std::endl;
}


} // namespace Interface
} // namespace Gomoku