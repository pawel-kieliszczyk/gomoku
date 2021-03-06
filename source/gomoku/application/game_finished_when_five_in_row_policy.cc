#include "gomoku/application/game_finished_when_five_in_row_policy.h"


namespace Gomoku
{
namespace Application
{


GameFinishedWhenFiveInRowPolicy::GameFinishedWhenFiveInRowPolicy(std::shared_ptr<Domain::IBoard> board_)
    : board(board_),
      movesLeft(board->getSize() * board->getSize() - board_->getStonesCount()),
      finished((movesLeft == 0) ? true : false)
{
    // TODO: check for 5 stones
    board->addObserver(*this);
}


GameFinishedWhenFiveInRowPolicy::~GameFinishedWhenFiveInRowPolicy()
{
    board->removeObserver(*this);
}


int GameFinishedWhenFiveInRowPolicy::getMovesLeft() const
{
    return movesLeft;
}

bool GameFinishedWhenFiveInRowPolicy::isFinished() const
{
    return finished;
}


std::experimental::optional<Domain::Stone> GameFinishedWhenFiveInRowPolicy::getWinner() const
{
    return winner;
}


void GameFinishedWhenFiveInRowPolicy::onStonePutAt(int x, int y)
{
    if(--movesLeft == 0)
        finished = true;

    const auto& stone = board->getStone(x, y);

    checkVertically(x, y, stone);
    checkHorizontally(x, y, stone);
    checkDiagonals(x, y, stone);
}


void GameFinishedWhenFiveInRowPolicy::onBoardCleared()
{
    movesLeft = board->getSize() * board->getSize();
    finished = false;
}


void GameFinishedWhenFiveInRowPolicy::checkVertically(int x, int y, const Domain::Stone& stone)
{
    check(x, y, stone, 0, 1);
}


void GameFinishedWhenFiveInRowPolicy::checkHorizontally(int x, int y, const Domain::Stone& stone)
{
    check(x, y, stone, 1, 0);
}


void GameFinishedWhenFiveInRowPolicy::checkDiagonals(int x, int y, const Domain::Stone& stone)
{
    check(x, y, stone, 1, 1);
    check(x, y, stone, 1, -1);
}


void GameFinishedWhenFiveInRowPolicy::check(int x, int y, const Domain::Stone& stone, int xOffset, int yOffset)
{
    int sameStonesLeft = 0;
    for(int i = 1; i < 5; ++i) {
        const int xx = x - i * xOffset;
        const int yy = y - i * yOffset;

        if(xx < 0)
            break;

        if(yy < 0)
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == stone)
            ++sameStonesLeft;
        else
            break;
    }

    int sameStonesRight = 0;
    for(int i = 1; i < 5; ++i) {
        const int xx = x + i * xOffset;
        const int yy = y + i * yOffset;

        if(xx == board->getSize())
            break;

        if(yy == board->getSize())
            break;

        if(!board->hasStone(xx, yy))
            break;

        if(board->getStone(xx, yy) == stone)
            ++sameStonesRight;
        else
            break;
    }

    const auto sameStones = sameStonesLeft + sameStonesRight + 1;
    if(sameStones >= 5)
    {
        finished = true;
        winner = stone;
    }
}


} // namespace Application
} // namespace Gomoku
