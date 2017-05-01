#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP


#include <memory>

#include "Domain/IBoard.hpp"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class BoardEvaluator
{
public:
    static constexpr int FIVE_STONES_WEIGHT = 1000000;
    static constexpr int OPEN_FOUR_STONES_WEIGHT = 1000;
    static constexpr int OPEN_THREE_STONES_WEIGHT = 100;
    static constexpr int OPEN_TWO_STONES_WEIGHT = 10;

    int evaluate(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY);

private:
    // five
    bool lastMoveMakesFiveStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY);

    bool lastMoveMakesFiveStonesHorizontally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesFiveStonesVertically(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesFiveStonesDiagonally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesFiveStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone,
            const int xOffset,
            const int yOffset);

    // open four
    bool lastMoveMakesOpenFourStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY);

    bool lastMoveMakesOpenFourStonesHorizontally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenFourStonesVertically(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenFourStonesDiagonally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenFourStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone,
            const int xOffset,
            const int yOffset);

    // open three
    bool lastMoveMakesOpenThreeStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY);

    bool lastMoveMakesOpenThreeStonesHorizontally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenThreeStonesVertically(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenThreeStonesDiagonally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenThreeStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone,
            const int xOffset,
            const int yOffset);

    // open two
    bool lastMoveMakesOpenTwoStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY);

    bool lastMoveMakesOpenTwoStonesHorizontally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenTwoStonesVertically(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenTwoStonesDiagonally(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone);

    bool lastMoveMakesOpenTwoStones(
            std::shared_ptr<Domain::IBoard> board,
            const int lastMoveX,
            const int lastMoveY,
            const Domain::Stone& lastMoveStone,
            const int xOffset,
            const int yOffset);

    bool isValidEmptyField(std::shared_ptr<Domain::IBoard> board, const int x, const int y) const;
    bool isValidField(std::shared_ptr<Domain::IBoard> board, const int x, const int y) const;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP
