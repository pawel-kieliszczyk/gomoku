#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ALPHABETAPLAYER_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ALPHABETAPLAYER_HPP


#include "Application/IPlayer.hpp"

#include <memory>

#include "Domain/IBoard.hpp"
#include "Domain/Stone.hpp"

#include "Application/ArtificialIntelligence/BoardEvaluator.hpp"
#include "Application/ArtificialIntelligence/BoardWithUndo.hpp"
#include "Application/ArtificialIntelligence/IMoveCandidatesSelector.hpp"


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
    int alphabeta(
            std::shared_ptr<BoardWithUndo> board,
            const int depth,
            int alpha,
            int beta,
            const bool maximizingPlayer,
            const int lastMoveX,
            const int lastMoveY);

    static const int ALPHA_BETA_DEPTH = 5;

    std::shared_ptr<Domain::IBoard> board;
    const Domain::Stone stone;
    std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector;

    BoardEvaluator boardEvaluator;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ALPHABETAPLAYER_HPP
