#include "Application/BoardEvaluator.hpp"

#include <limits>


namespace Gomoku
{
namespace Application
{


int BoardEvaluator::evaluate(std::shared_ptr<Domain::IBoard> board)
{
    if(hasFiveBlackStonesHorizontally(board))
        return std::numeric_limits<int>::max();

    if(hasFiveWhiteStonesHorizontally(board))
        return std::numeric_limits<int>::min();

    if(hasFiveBlackStonesVertically(board))
        return std::numeric_limits<int>::max();

    if(hasFiveWhiteStonesVertically(board))
        return std::numeric_limits<int>::min();

    return 0;
}


bool BoardEvaluator::hasFiveBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesHorizontally(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasFiveWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesHorizontally(board, Domain::Stone::White);
}


bool BoardEvaluator::hasFiveStonesHorizontally(
        std::shared_ptr<Domain::IBoard> board,
        const Domain::Stone& stone)
{
    for(int x = 0; x < board->getSize(); ++x)
    {
        int counter = 0;
        for(int y = 0; y < board->getSize(); ++y)
        {
            if(!board->hasStone(x, y))
            {
                counter = 0;
                continue;
            }

            if(board->getStone(x, y) == stone)
                ++counter;
            else
                counter = 0;

            if(counter == 5)
                return true;
        }
    }

    return false;
}


bool BoardEvaluator::hasFiveBlackStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesVertically(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasFiveWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesVertically(board, Domain::Stone::White);
}


bool BoardEvaluator::hasFiveStonesVertically(
        std::shared_ptr<Domain::IBoard> board,
        const Domain::Stone& stone)
{
    for(int y = 0; y < board->getSize(); ++y)
    {
        int counter = 0;
        for(int x = 0; x < board->getSize(); ++x)
        {
            if(!board->hasStone(x, y))
            {
                counter = 0;
                continue;
            }

            if(board->getStone(x, y) == stone)
                ++counter;
            else
                counter = 0;

            if(counter == 5)
                return true;
        }
    }

    return false;
}


} // namespace Application
} // namespace Gomoku
