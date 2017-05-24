#ifndef GOMOKU_APPLICATION_GAMECONTROLLERFACTORY_HPP
#define GOMOKU_APPLICATION_GAMECONTROLLERFACTORY_HPP


#include <memory>

#include "gomoku/application/game_controller.h"
#include "gomoku/application/iplayer_factory.h"
#include "gomoku/domain/iboard.h"


namespace Gomoku
{
namespace Application
{


class GameControllerFactory
{
public:
    std::shared_ptr<GameController> create(
            std::shared_ptr<Domain::IBoard> board,
            std::shared_ptr<IPlayerFactory> playerFactory1,
            std::shared_ptr<IPlayerFactory> playerFactory2);
};


} // namespace Application
} // namespace Gomoku


#endif //GOMOKU_APPLICATION_GAMECONTROLLERFACTORY_HPP
