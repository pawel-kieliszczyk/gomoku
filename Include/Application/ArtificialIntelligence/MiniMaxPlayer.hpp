#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP


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
            int depth,
            bool maximizingPlayer);

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
