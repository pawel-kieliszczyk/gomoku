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


int BoardEvaluator::evaluate(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY)
{
    if(lastMoveMakesFiveStones(board, lastMoveX, lastMoveY))
    {
        const auto lastMoveStone = board->getStone(lastMoveX, lastMoveY);
        if(lastMoveStone == Domain::Stone::Black)
            return FIVE_STONES_WEIGHT;
        else
            return -FIVE_STONES_WEIGHT;
    }

    if(lastMoveMakesOpenFourStones(board, lastMoveX, lastMoveY))
    {
        const auto lastMoveStone = board->getStone(lastMoveX, lastMoveY);
        if(lastMoveStone == Domain::Stone::Black)
            return OPEN_FOUR_STONES_WEIGHT;
        else
            return -OPEN_FOUR_STONES_WEIGHT;
    }

    if(lastMoveMakesOpenThreeStones(board, lastMoveX, lastMoveY))
    {
        const auto lastMoveStone = board->getStone(lastMoveX, lastMoveY);
        if(lastMoveStone == Domain::Stone::Black)
            return OPEN_THREE_STONES_WEIGHT;
        else
            return -OPEN_THREE_STONES_WEIGHT;
    }

    if(lastMoveMakesOpenTwoStones(board, lastMoveX, lastMoveY))
    {
        const auto lastMoveStone = board->getStone(lastMoveX, lastMoveY);
        if(lastMoveStone == Domain::Stone::Black)
            return OPEN_TWO_STONES_WEIGHT;
        else
            return -OPEN_TWO_STONES_WEIGHT;
    }

    return 0;
}


bool BoardEvaluator::lastMoveMakesFiveStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY)
{
    const auto& lastMoveStone = board->getStone(lastMoveX, lastMoveY);

    if(lastMoveMakesFiveStonesHorizontally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesFiveStonesVertically(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesFiveStonesDiagonally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    return false;
}


bool BoardEvaluator::lastMoveMakesFiveStonesHorizontally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesFiveStones(board, lastMoveX, lastMoveY, lastMoveStone, 0, 1);
}


bool BoardEvaluator::lastMoveMakesFiveStonesVertically(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesFiveStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 0);
}


bool BoardEvaluator::lastMoveMakesFiveStonesDiagonally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return (lastMoveMakesFiveStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 1)
            || lastMoveMakesFiveStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, -1));
}


bool BoardEvaluator::lastMoveMakesFiveStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone,
        const int xOffset,
        const int yOffset)
{
    int sameStonesLeft = 0;
    for(int i = 1; i < 5; ++i) {
        const int xx = lastMoveX - i * xOffset;
        const int yy = lastMoveY - i * yOffset;

        if(xx < 0)
            break;

        if(yy < 0)
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesLeft;
        else
            break;
    }

    int sameStonesRight = 0;
    for(int i = 1; i < 5; ++i) {
        const int xx = lastMoveX + i * xOffset;
        const int yy = lastMoveY + i * yOffset;

        if(xx == board->getSize())
            break;

        if(yy == board->getSize())
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesRight;
        else
            break;
    }

    const auto sameStones = sameStonesLeft + sameStonesRight + 1;
    return (sameStones == 5);
}


bool BoardEvaluator::lastMoveMakesOpenFourStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY)
{
    const auto& lastMoveStone = board->getStone(lastMoveX, lastMoveY);

    if(lastMoveMakesOpenFourStonesHorizontally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesOpenFourStonesVertically(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesOpenFourStonesDiagonally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    return false;
}


bool BoardEvaluator::lastMoveMakesOpenFourStonesHorizontally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesOpenFourStones(board, lastMoveX, lastMoveY, lastMoveStone, 0, 1);
}


bool BoardEvaluator::lastMoveMakesOpenFourStonesVertically(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesOpenFourStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 0);
}


bool BoardEvaluator::lastMoveMakesOpenFourStonesDiagonally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return (lastMoveMakesOpenFourStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 1)
            || lastMoveMakesOpenFourStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, -1));
}


bool BoardEvaluator::lastMoveMakesOpenFourStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone,
        const int xOffset,
        const int yOffset)
{
    int sameStonesLeft = 0;
    for(int i = 1; i < 4; ++i) {
        const int xx = lastMoveX - i * xOffset;
        const int yy = lastMoveY - i * yOffset;

        if(xx < 0)
            break;

        if(yy < 0)
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesLeft;
        else
            break;
    }

    int sameStonesRight = 0;
    for(int i = 1; i < 4; ++i) {
        const int xx = lastMoveX + i * xOffset;
        const int yy = lastMoveY + i * yOffset;

        if(xx == board->getSize())
            break;

        if(yy == board->getSize())
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesRight;
        else
            break;
    }

    const auto sameStones = sameStonesLeft + sameStonesRight + 1;

    if(sameStones != 4)
        return false;

    const int leftBoundX = lastMoveX - ((sameStonesLeft + 1) * xOffset);
    const int leftBoundY = lastMoveY - ((sameStonesLeft + 1) * yOffset);

    const int rightBoundX = lastMoveX + ((sameStonesRight + 1) * xOffset);
    const int rightBoundY = lastMoveY + ((sameStonesRight + 1) * yOffset);

    if(isValidEmptyField(board, leftBoundX, leftBoundY) && isValidEmptyField(board, rightBoundX, rightBoundY))
        return true;

    return false;
}


bool BoardEvaluator::lastMoveMakesOpenThreeStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY)
{
    const auto& lastMoveStone = board->getStone(lastMoveX, lastMoveY);

    if(lastMoveMakesOpenThreeStonesHorizontally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesOpenThreeStonesVertically(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesOpenThreeStonesDiagonally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    return false;
}


bool BoardEvaluator::lastMoveMakesOpenThreeStonesHorizontally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesOpenThreeStones(board, lastMoveX, lastMoveY, lastMoveStone, 0, 1);
}


bool BoardEvaluator::lastMoveMakesOpenThreeStonesVertically(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesOpenThreeStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 0);
}


bool BoardEvaluator::lastMoveMakesOpenThreeStonesDiagonally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return (lastMoveMakesOpenThreeStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 1)
            || lastMoveMakesOpenThreeStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, -1));
}


bool BoardEvaluator::lastMoveMakesOpenThreeStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone,
        const int xOffset,
        const int yOffset)
{
    int sameStonesLeft = 0;
    for(int i = 1; i < 3; ++i) {
        const int xx = lastMoveX - i * xOffset;
        const int yy = lastMoveY - i * yOffset;

        if(xx < 0)
            break;

        if(yy < 0)
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesLeft;
        else
            break;
    }

    int sameStonesRight = 0;
    for(int i = 1; i < 3; ++i) {
        const int xx = lastMoveX + i * xOffset;
        const int yy = lastMoveY + i * yOffset;

        if(xx == board->getSize())
            break;

        if(yy == board->getSize())
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesRight;
        else
            break;
    }

    const auto sameStones = sameStonesLeft + sameStonesRight + 1;

    if(sameStones != 3)
        return false;

    const int leftBoundX = lastMoveX - ((sameStonesLeft + 1) * xOffset);
    const int leftBoundY = lastMoveY - ((sameStonesLeft + 1) * yOffset);

    const int rightBoundX = lastMoveX + ((sameStonesRight + 1) * xOffset);
    const int rightBoundY = lastMoveY + ((sameStonesRight + 1) * yOffset);

    if(isValidEmptyField(board, leftBoundX, leftBoundY) && isValidEmptyField(board, rightBoundX, rightBoundY))
        return true;

    return false;
}


bool BoardEvaluator::lastMoveMakesOpenTwoStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY)
{
    const auto& lastMoveStone = board->getStone(lastMoveX, lastMoveY);

    if(lastMoveMakesOpenTwoStonesHorizontally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesOpenTwoStonesVertically(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    if(lastMoveMakesOpenTwoStonesDiagonally(board, lastMoveX, lastMoveY, lastMoveStone))
        return true;

    return false;
}


bool BoardEvaluator::lastMoveMakesOpenTwoStonesHorizontally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesOpenTwoStones(board, lastMoveX, lastMoveY, lastMoveStone, 0, 1);
}


bool BoardEvaluator::lastMoveMakesOpenTwoStonesVertically(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return lastMoveMakesOpenTwoStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 0);
}


bool BoardEvaluator::lastMoveMakesOpenTwoStonesDiagonally(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone)
{
    return (lastMoveMakesOpenTwoStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, 1)
            || lastMoveMakesOpenTwoStones(board, lastMoveX, lastMoveY, lastMoveStone, 1, -1));
}


bool BoardEvaluator::lastMoveMakesOpenTwoStones(
        std::shared_ptr<Domain::IBoard> board,
        const int lastMoveX,
        const int lastMoveY,
        const Domain::Stone& lastMoveStone,
        const int xOffset,
        const int yOffset)
{
    int sameStonesLeft = 0;
    for(int i = 1; i < 2; ++i) {
        const int xx = lastMoveX - i * xOffset;
        const int yy = lastMoveY - i * yOffset;

        if(xx < 0)
            break;

        if(yy < 0)
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesLeft;
        else
            break;
    }

    int sameStonesRight = 0;
    for(int i = 1; i < 2; ++i) {
        const int xx = lastMoveX + i * xOffset;
        const int yy = lastMoveY + i * yOffset;

        if(xx == board->getSize())
            break;

        if(yy == board->getSize())
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == lastMoveStone)
            ++sameStonesRight;
        else
            break;
    }

    const auto sameStones = sameStonesLeft + sameStonesRight + 1;

    if(sameStones != 2)
        return false;

    const int leftBoundX = lastMoveX - ((sameStonesLeft + 1) * xOffset);
    const int leftBoundY = lastMoveY - ((sameStonesLeft + 1) * yOffset);

    const int rightBoundX = lastMoveX + ((sameStonesRight + 1) * xOffset);
    const int rightBoundY = lastMoveY + ((sameStonesRight + 1) * yOffset);

    if(isValidEmptyField(board, leftBoundX, leftBoundY) && isValidEmptyField(board, rightBoundX, rightBoundY))
        return true;

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
