#ifndef GOMOKU_APPLICATION_BOARDEVALUATOR_HPP
#define GOMOKU_APPLICATION_BOARDEVALUATOR_HPP


#include <memory>

#include "Domain/IBoard.hpp"


namespace Gomoku
{
namespace Application
{


class BoardEvaluator
{
public:
    int evaluate(std::shared_ptr<Domain::IBoard> board);

private:
    bool hasFiveBlackStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveWhiteStonesHorizontally(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveStonesHorizontally(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);

    bool hasFiveBlackStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveWhiteStonesVertically(std::shared_ptr<Domain::IBoard> board);
    bool hasFiveStonesVertically(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone);
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_BOARDEVALUATOR_HPP
