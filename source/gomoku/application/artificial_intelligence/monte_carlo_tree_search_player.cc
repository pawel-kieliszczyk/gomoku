#include "gomoku/application/artificial_intelligence/monte_carlo_tree_search_player.h"

#include <utility>
#include <vector>


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


MonteCarloTreeSearchPlayer::MonteCarloTreeSearchPlayer(
        std::shared_ptr<Domain::IBoard> board_,
        const Domain::Stone& stone_,
        std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_)
    : board(board_),
      stone(stone_),
      moveCandidatesSelector(moveCandidatesSelector_),
      monteCarloTree(board, stone, moveCandidatesSelector)
{
}


void MonteCarloTreeSearchPlayer::performMove()
{
    for(int i = 0; i < simulationsLimit; ++i)
        monteCarloTree.runSimulation();

    const auto move = monteCarloTree.getBestMove();
    board->putStone(move.first, move.second, stone);
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
