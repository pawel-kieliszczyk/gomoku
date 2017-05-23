#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ALPHABETAPLAYER_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ALPHABETAPLAYER_HPP


#include "application/iplayer.h"

#include <memory>
#include <utility>
#include <vector>

#include "application/artificial_intelligence/board_evaluator.h"
#include "application/artificial_intelligence/board_with_undo.h"
#include "application/artificial_intelligence/imove_candidates_selector.h"
#include "domain/iboard.h"
#include "domain/stone.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class AlphaBetaPlayer : public IPlayer
{
public:
    AlphaBetaPlayer(
            std::shared_ptr<Domain::IBoard> board_,
            const Domain::Stone& stone_,
            std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_);

    void performMove() override;

private:
    struct AlphaBetaRank
    {
        int value;
        int valueReachedAtDepth;

        AlphaBetaRank(const int value_, const int valueReachedAtDepth_) : value(value_), valueReachedAtDepth(valueReachedAtDepth_) {}
    };

    AlphaBetaRank alphabeta(
            std::shared_ptr<BoardWithUndo> board,
            const int depth,
            int alpha,
            int beta,
            const bool maximizingPlayer,
            const int lastMoveX,
            const int lastMoveY);

    void rankAndLimitMoves(
            std::shared_ptr<BoardWithUndo> board,
            std::vector<std::pair<int, int>>& moves,
            const Domain::Stone& stone);

    static const int ALPHA_BETA_DEPTH = 8;
    static const int RANKED_MOVES_LIMIT = 5;

    std::shared_ptr<Domain::IBoard> board;
    const Domain::Stone stone;
    std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector;

    BoardEvaluator boardEvaluator;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ALPHABETAPLAYER_HPP
