#include "application/artificial_intelligence/AdjacentMoveCandidatesSelector.hpp"

#include <iterator>


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


std::vector<std::pair<int, int>> AdjacentMoveCandidatesSelector::selectMoves(std::shared_ptr<Domain::IBoard> board)
{
    std::set<std::pair<int, int>> validMoves;

    for(int x = 0; x < board->getSize(); ++x)
    {
        for(int y = 0; y < board->getSize(); ++y)
        {
            if(board->hasStone(x, y))
            {
                insertMoveIfValid(validMoves, board, x-1, y-1);
                insertMoveIfValid(validMoves, board, x-1, y);
                insertMoveIfValid(validMoves, board, x-1, y+1);
                insertMoveIfValid(validMoves, board, x, y-1);
                insertMoveIfValid(validMoves, board, x, y+1);
                insertMoveIfValid(validMoves, board, x+1, y-1);
                insertMoveIfValid(validMoves, board, x+1, y);
                insertMoveIfValid(validMoves, board, x+1, y+1);
            }
        }
    }

    if(validMoves.empty())
        validMoves.insert(std::make_pair(7, 7));

    return std::vector<std::pair<int, int>>(std::begin(validMoves), std::end(validMoves));
}


void AdjacentMoveCandidatesSelector::insertMoveIfValid(
        std::set<std::pair<int, int>>& validMoves,
        std::shared_ptr<Domain::IBoard> board,
        const int x,
        const int y)
{
    if((x < 0) || (x >= board->getSize()))
        return;

    if((y < 0) || (y >= board->getSize()))
        return;

    if(board->hasStone(x, y))
        return;

    validMoves.insert(std::make_pair(x, y));
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
