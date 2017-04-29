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
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP
