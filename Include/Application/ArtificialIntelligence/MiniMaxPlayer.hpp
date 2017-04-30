#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP


#include "Application/IPlayer.hpp"

#include <memory>
#include <set>
#include <utility>
#include <vector>

#include "Domain/IBoard.hpp"
#include "Domain/Stone.hpp"

#include "Application/ArtificialIntelligence/BoardEvaluator.hpp"
#include "Application/ArtificialIntelligence/BoardWithUndo.hpp"


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
            const Domain::Stone& stone_);

    void performMove() override;

private:
    int minimax(
            std::shared_ptr<BoardWithUndo> board,
            int depth,
            bool maximizingPlayer);

    std::vector<std::pair<int, int>> getValidMoves(
            std::shared_ptr<BoardWithUndo> board);

    void insertMoveIfValid(
            std::set<std::pair<int, int>>& validMoves,
            std::shared_ptr<BoardWithUndo> board,
            const int x,
            const int y);

    static const int MINIMAX_DEPTH = 4;

    std::shared_ptr<Domain::IBoard> board;
    const Domain::Stone stone;

    BoardEvaluator boardEvaluator;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYER_HPP
