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
    int evaluate(std::shared_ptr<Domain::IBoard> board);

private:
    // five stones
    bool hasFiveBlackStonesInRow(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveBlackStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveBlackStonesDiagonally(std::shared_ptr<Domain::IBoard> board);

    bool hasFiveWhiteStonesInRow(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveWhiteStonesDiagonally(std::shared_ptr<Domain::IBoard> board);

    bool hasFiveStonesHorizontally(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasFiveStonesVertically(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasFiveStonesDiagonally1(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasFiveStonesDiagonally2(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);

    // four open stones
    bool hasFourOpenBlackStonesInRow(std::shared_ptr<Domain::IBoard> board);
    bool hasFourOpenBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasFourOpenBlackStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasFourOpenBlackStonesDiagonally(std::shared_ptr<Domain::IBoard> board);

    bool hasFourOpenWhiteStonesInRow(std::shared_ptr<Domain::IBoard> board);
    bool hasFourOpenWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasFourOpenWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasFourOpenWhiteStonesDiagonally(std::shared_ptr<Domain::IBoard> board);

    bool hasFourOpenStonesHorizontally(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasFourOpenStonesVertically(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasFourOpenStonesDiagonally1(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasFourOpenStonesDiagonally2(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);

    // three open stones
    bool hasThreeOpenBlackStonesInRow(std::shared_ptr<Domain::IBoard> board);
    bool hasThreeOpenBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasThreeOpenBlackStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasThreeOpenBlackStonesDiagonally(std::shared_ptr<Domain::IBoard> board);

    bool hasThreeOpenWhiteStonesInRow(std::shared_ptr<Domain::IBoard> board);
    bool hasThreeOpenWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasThreeOpenWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasThreeOpenWhiteStonesDiagonally(std::shared_ptr<Domain::IBoard> board);

    bool hasThreeOpenStonesHorizontally(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasThreeOpenStonesVertically(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasThreeOpenStonesDiagonally1(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
    bool hasThreeOpenStonesDiagonally2(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);

    bool isValidEmptyField(std::shared_ptr<Domain::IBoard> board, const int x, const int y) const;
    bool isValidField(std::shared_ptr<Domain::IBoard> board, const int x, const int y) const;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP
