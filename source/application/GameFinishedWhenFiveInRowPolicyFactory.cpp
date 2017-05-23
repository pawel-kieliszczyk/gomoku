#include "application/GameFinishedWhenFiveInRowPolicyFactory.hpp"

#include <memory>

#include "application/GameFinishedWhenFiveInRowPolicy.hpp"


namespace Gomoku
{
namespace Application
{


std::shared_ptr<IGameFinishedPolicy> GameFinishedWhenFiveInRowPolicyFactory::create(std::shared_ptr<Domain::IBoard> board)
{
    return std::make_shared<GameFinishedWhenFiveInRowPolicy>(board);
}


} // namespace Application
} // namespace Gomoku
