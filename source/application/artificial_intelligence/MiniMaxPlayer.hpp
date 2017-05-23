#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP


#include "application/IPlayer.hpp"

#include <memory>

#include "application/artificial_intelligence/BoardEvaluator.hpp"
#include "application/artificial_intelligence/BoardWithUndo.hpp"
#include "application/artificial_intelligence/IMoveCandidatesSelector.hpp"
#include "domain/IBoard.hpp"
#include "domain/Stone.hpp"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class MiniMaxPlayer : public IPlayer
{
public:
    MiniMaxPlayer(
            std::shared_ptr<Domain::IBoard> board_,
            const Domain::Stone& stone_,
            std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_);

    void performMove() override;

private:
    int minimax(
            std::shared_ptr<BoardWithUndo> board,
            const int depth,
            const bool maximizingPlayer,
            const int lastMoveX,
            const int lastMoveY);

    static const int MINIMAX_DEPTH = 4;

    std::shared_ptr<Domain::IBoard> board;
    const Domain::Stone stone;
    std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector;

    BoardEvaluator boardEvaluator;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP
