#include "gomoku/application/artificial_intelligence/board_with_undo.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


BoardWithUndo::BoardWithUndo(std::shared_ptr<Domain::IBoard> toCopy)
{
    for(int x = 0; x < toCopy->getSize(); ++x)
    {
        for(int y = 0; y < toCopy->getSize(); ++y)
        {
            if(toCopy->hasStone(x, y))
            {
                putStone(x, y, toCopy->getStone(x, y));
            }
        }
    }
}


int BoardWithUndo::getSize() const
{
    return originalBoard.getSize();
}


void BoardWithUndo::putStone(int x, int y, const Domain::Stone& stone)
{
    originalBoard.putStone(x, y, stone);
    moves.push(std::make_pair(x, y));
}


Domain::Stone BoardWithUndo::getStone(int x, int y) const
{
    return originalBoard.getStone(x, y);
}


void BoardWithUndo::removeStone(int x, int y)
{
    originalBoard.removeStone(x, y);
}


bool BoardWithUndo::hasStone(int x, int y) const
{
    return originalBoard.hasStone(x, y);
}


void BoardWithUndo::clear()
{
    originalBoard.clear();
}

void BoardWithUndo::addObserver(Domain::IBoardObserver& observer)
{
    originalBoard.addObserver(observer);
}


void BoardWithUndo::undoMove()
{
    originalBoard.removeStone(moves.top().first, moves.top().second);
    moves.pop();
}


} // namespace ArtificialIntelligence
} // namespace Domain
} // namespace Gomoku
