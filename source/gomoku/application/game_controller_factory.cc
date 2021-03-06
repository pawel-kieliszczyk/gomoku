#include "gomoku/application/game_controller_factory.h"

#include <memory>

#include "gomoku/application/game_finished_when_five_in_row_policy_factory.h"


namespace Gomoku
{
namespace Application
{


std::shared_ptr<GameController> GameControllerFactory::create(
        std::shared_ptr<Domain::IBoard> board,
        std::shared_ptr<IPlayerFactory> playerFactory1,
        std::shared_ptr<IPlayerFactory> playerFactory2)
{
    auto gameFinishedPolicyFactory = std::make_shared<GameFinishedWhenFiveInRowPolicyFactory>();
    auto controller = std::make_shared<GameController>(board, playerFactory1, playerFactory2, gameFinishedPolicyFactory);

    return controller;
}


} // namespace Application
} // namespace Gomoku
