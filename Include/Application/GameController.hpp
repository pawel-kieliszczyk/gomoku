#ifndef GOMOKU_APPLICATION_GAMECONTROLLER_HPP
#define GOMOKU_APPLICATION_GAMECONTROLLER_HPP


#include <memory>

#include "Domain/IBoard.hpp"


namespace Gomoku
{
namespace Application
{


class GameController
{
public:
    GameController(std::shared_ptr<Domain::IBoard> board_);

    void startNewGame();

private:
    std::shared_ptr<Domain::IBoard> board;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_GAMECONTROLLER_HPP
