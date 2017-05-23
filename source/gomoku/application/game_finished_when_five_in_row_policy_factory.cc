#include "gomoku/application/game_finished_when_five_in_row_policy_factory.h"

#include <memory>

#include "gomoku/application/game_finished_when_five_in_row_policy.h"


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
