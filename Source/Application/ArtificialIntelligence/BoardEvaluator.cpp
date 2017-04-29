#include "Application/ArtificialIntelligence/BoardEvaluator.hpp"

#include <limits>
#include <utility>
#include <vector>


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


int BoardEvaluator::evaluate(std::shared_ptr<Domain::IBoard> board)
{
    if(hasFiveBlackStonesInRow(board))
        return std::numeric_limits<int>::max();

    if(hasFiveWhiteStonesInRow(board))
        return std::numeric_limits<int>::min();

    return 0;
}

bool BoardEvaluator::hasFiveBlackStonesInRow(std::shared_ptr<Domain::IBoard> board)
{
    if(hasFiveBlackStonesHorizontally(board))
        return true;

    if(hasFiveBlackStonesVertically(board))
        return true;

    if(hasFiveBlackStonesDiagonally(board))
        return true;

    return false;
}


bool BoardEvaluator::hasFiveBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesHorizontally(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasFiveBlackStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesVertically(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasFiveBlackStonesDiagonally(std::shared_ptr<Domain::IBoard> board)
{
    return (hasFiveStonesDiagonally1(board, Domain::Stone::Black) || hasFiveStonesDiagonally2(board, Domain::Stone::Black));
}


bool BoardEvaluator::hasFiveWhiteStonesInRow(std::shared_ptr<Domain::IBoard> board)
{
    if(hasFiveWhiteStonesHorizontally(board))
        return true;

    if(hasFiveWhiteStonesVertically(board))
        return true;

    if(hasFiveWhiteStonesDiagonally(board))
        return true;

    return false;
}


bool BoardEvaluator::hasFiveWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesHorizontally(board, Domain::Stone::White);
}


bool BoardEvaluator::hasFiveWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasFiveStonesVertically(board, Domain::Stone::White);
}


bool BoardEvaluator::hasFiveWhiteStonesDiagonally(std::shared_ptr<Domain::IBoard> board)
{
    return (hasFiveStonesDiagonally1(board, Domain::Stone::White) || hasFiveStonesDiagonally2(board, Domain::Stone::White));
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


bool BoardEvaluator::hasFiveStonesDiagonally1(
        std::shared_ptr<Domain::IBoard> board,
        const Domain::Stone& stone)
{
    std::vector<std::pair<int, int>> startingPoints;
    for(int y = 0; y < (board->getSize() - 4); ++y)
        startingPoints.push_back(std::make_pair(0, y));
    for(int x = 1; x < (board->getSize() - 4); ++x)
        startingPoints.push_back(std::make_pair(x, 0));

    for(const auto& point : startingPoints)
    {
        int counter = 0;
        for(int x = point.first, y = point.second; (x < board->getSize()) && (y < board->getSize()); ++x, ++y)
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


bool BoardEvaluator::hasFiveStonesDiagonally2(
        std::shared_ptr<Domain::IBoard> board,
        const Domain::Stone& stone)
{
    std::vector<std::pair<int, int>> startingPoints;
    for(int y = 4; y < board->getSize(); ++y)
        startingPoints.push_back(std::make_pair(0, y));
    for(int x = 1; x < (board->getSize() - 4); ++x)
        startingPoints.push_back(std::make_pair(x, 14));

    for(const auto& point : startingPoints)
    {
        int counter = 0;
        for(int x = point.first, y = point.second; (x < board->getSize()) && (y >= 0); ++x, --y)
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


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
