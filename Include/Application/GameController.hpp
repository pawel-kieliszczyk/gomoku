#ifndef GOMOKU_APPLICATION_GAMECONTROLLER_HPP
#define GOMOKU_APPLICATION_GAMECONTROLLER_HPP


#include <memory>

#include "Domain/IBoard.hpp"

#include "IPlayer.hpp"
#include "IPlayerFactory.hpp"
#include "IGameFinishedPolicy.hpp"
#include "IGameFinishedPolicyFactory.hpp"


namespace Gomoku
{
namespace Application
{


class GameController
{
public:
    GameController(
            std::shared_ptr<Domain::IBoard> board_,
            std::shared_ptr<IPlayerFactory> playerFactory1_,
            std::shared_ptr<IPlayerFactory> playerFactory2_,
            std::shared_ptr<IGameFinishedPolicyFactory> gameFinishedPolicyFactory_);

    void initializeNewGame();

    void play();

private:
    std::shared_ptr<Domain::IBoard> board;
    std::shared_ptr<IPlayerFactory> playerFactory1;
    std::shared_ptr<IPlayerFactory> playerFactory2;
    std::shared_ptr<IGameFinishedPolicyFactory> gameFinishedPolicyFactory;

    std::shared_ptr<IPlayer> playerBlack;
    std::shared_ptr<IPlayer> playerWhite;
    std::shared_ptr<IGameFinishedPolicy> gameFinishedPolicy;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_GAMECONTROLLER_HPP
