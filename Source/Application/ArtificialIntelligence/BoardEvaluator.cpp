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

    if(hasFourOpenBlackStonesInRow(board))
        return std::numeric_limits<int>::max();

    if(hasFourOpenWhiteStonesInRow(board))
        return std::numeric_limits<int>::min();

    if(hasThreeOpenBlackStonesInRow(board))
        return 1;

    if(hasThreeOpenWhiteStonesInRow(board))
        return -1;

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


bool BoardEvaluator::hasFourOpenBlackStonesInRow(std::shared_ptr<Domain::IBoard> board)
{
    if(hasFourOpenBlackStonesHorizontally(board))
        return true;

    if(hasFourOpenBlackStonesVertically(board))
        return true;

    if(hasFourOpenBlackStonesDiagonally(board))
        return true;

    return false;
}


bool BoardEvaluator::hasFourOpenBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasFourOpenStonesHorizontally(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasFourOpenBlackStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasFourOpenStonesVertically(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasFourOpenBlackStonesDiagonally(std::shared_ptr<Domain::IBoard> board)
{
    return (hasFourOpenStonesDiagonally1(board, Domain::Stone::Black) || hasFourOpenStonesDiagonally2(board, Domain::Stone::Black));
}


bool BoardEvaluator::hasFourOpenWhiteStonesInRow(std::shared_ptr<Domain::IBoard> board)
{
    if(hasFourOpenWhiteStonesHorizontally(board))
        return true;

    if(hasFourOpenWhiteStonesVertically(board))
        return true;

    if(hasFourOpenWhiteStonesDiagonally(board))
        return true;

    return false;
}


bool BoardEvaluator::hasFourOpenWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasFourOpenStonesHorizontally(board, Domain::Stone::White);
}


bool BoardEvaluator::hasFourOpenWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasFourOpenStonesVertically(board, Domain::Stone::White);
}


bool BoardEvaluator::hasFourOpenWhiteStonesDiagonally(std::shared_ptr<Domain::IBoard> board)
{
    return (hasFourOpenStonesDiagonally1(board, Domain::Stone::White) || hasFourOpenStonesDiagonally2(board, Domain::Stone::White));
}


bool BoardEvaluator::hasFourOpenStonesHorizontally(
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

            if(counter == 4)
            {
                const int leftX = x;
                const int leftY = y - 4;

                const int rightX = x;
                const int rightY = y + 1;

                if(isValidEmptyField(board, leftX, leftY) && isValidEmptyField(board, rightX, rightY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasFourOpenStonesVertically(
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

            if(counter == 4)
            {
                const int topX = x - 4;
                const int topY = y;

                const int bottomX = x + 1;
                const int bottomY = y;

                if(isValidEmptyField(board, topX, topY) && isValidEmptyField(board, bottomX, bottomY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasFourOpenStonesDiagonally1(
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

            if(counter == 4)
            {
                const int topX = x - 4;
                const int topY = y - 4;

                const int bottomX = x + 1;
                const int bottomY = y + 1;

                if(isValidEmptyField(board, topX, topY) && isValidEmptyField(board, bottomX, bottomY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasFourOpenStonesDiagonally2(
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

            if(counter == 4)
            {
                const int topX = x - 4;
                const int topY = y + 4;

                const int bottomX = x + 1;
                const int bottomY = y - 1;

                if(isValidEmptyField(board, topX, topY) && isValidEmptyField(board, bottomX, bottomY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasThreeOpenBlackStonesInRow(std::shared_ptr<Domain::IBoard> board)
{
    if(hasThreeOpenBlackStonesHorizontally(board))
        return true;

    if(hasThreeOpenBlackStonesVertically(board))
        return true;

    if(hasThreeOpenBlackStonesDiagonally(board))
        return true;

    return false;
}


bool BoardEvaluator::hasThreeOpenBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasThreeOpenStonesHorizontally(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasThreeOpenBlackStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasThreeOpenStonesVertically(board, Domain::Stone::Black);
}


bool BoardEvaluator::hasThreeOpenBlackStonesDiagonally(std::shared_ptr<Domain::IBoard> board)
{
    return (hasThreeOpenStonesDiagonally1(board, Domain::Stone::Black) || hasThreeOpenStonesDiagonally2(board, Domain::Stone::Black));
}


bool BoardEvaluator::hasThreeOpenWhiteStonesInRow(std::shared_ptr<Domain::IBoard> board)
{
    if(hasThreeOpenWhiteStonesHorizontally(board))
        return true;

    if(hasThreeOpenWhiteStonesVertically(board))
        return true;

    if(hasThreeOpenWhiteStonesDiagonally(board))
        return true;

    return false;
}


bool BoardEvaluator::hasThreeOpenWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board)
{
    return hasThreeOpenStonesHorizontally(board, Domain::Stone::White);
}


bool BoardEvaluator::hasThreeOpenWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board)
{
    return hasThreeOpenStonesVertically(board, Domain::Stone::White);
}


bool BoardEvaluator::hasThreeOpenWhiteStonesDiagonally(std::shared_ptr<Domain::IBoard> board)
{
    return (hasThreeOpenStonesDiagonally1(board, Domain::Stone::White) || hasThreeOpenStonesDiagonally2(board, Domain::Stone::White));
}


bool BoardEvaluator::hasThreeOpenStonesHorizontally(
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

            if(counter == 3)
            {
                const int leftX = x;
                const int leftY = y - 3;

                const int rightX = x;
                const int rightY = y + 1;

                if(isValidEmptyField(board, leftX, leftY) && isValidEmptyField(board, rightX, rightY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasThreeOpenStonesVertically(
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

            if(counter == 3)
            {
                const int topX = x - 3;
                const int topY = y;

                const int bottomX = x + 1;
                const int bottomY = y;

                if(isValidEmptyField(board, topX, topY) && isValidEmptyField(board, bottomX, bottomY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasThreeOpenStonesDiagonally1(
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

            if(counter == 3)
            {
                const int topX = x - 3;
                const int topY = y - 3;

                const int bottomX = x + 1;
                const int bottomY = y + 1;

                if(isValidEmptyField(board, topX, topY) && isValidEmptyField(board, bottomX, bottomY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::hasThreeOpenStonesDiagonally2(
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

            if(counter == 3)
            {
                const int topX = x - 3;
                const int topY = y + 3;

                const int bottomX = x + 1;
                const int bottomY = y - 1;

                if(isValidEmptyField(board, topX, topY) && isValidEmptyField(board, bottomX, bottomY))
                    return true;
            }
        }
    }

    return false;
}


bool BoardEvaluator::isValidEmptyField(std::shared_ptr<Domain::IBoard> board, const int x, const int y) const
{
    if(!isValidField(board, x, y))
        return false;

    return (!board->hasStone(x, y));
}


bool BoardEvaluator::isValidField(std::shared_ptr<Domain::IBoard> board, const int x, const int y) const
{
    if((x < 0) || (x >= board->getSize()))
        return false;

    if((y < 0) || (y >= board->getSize()))
        return false;

    return true;
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
