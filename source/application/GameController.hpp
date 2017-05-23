#ifndef GOMOKU_APPLICATION_GAMECONTROLLER_HPP
#define GOMOKU_APPLICATION_GAMECONTROLLER_HPP


#include <memory>

#include "application/IPlayer.hpp"
#include "application/IPlayerFactory.hpp"
#include "application/IGameFinishedPolicy.hpp"
#include "application/IGameFinishedPolicyFactory.hpp"
#include "domain/IBoard.hpp"


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
