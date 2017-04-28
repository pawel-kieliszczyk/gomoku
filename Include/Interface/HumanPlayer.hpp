#ifndef GOMOKU_INTERFACE_HUMANPLAYER_HPP
#define GOMOKU_INTERFACE_HUMANPLAYER_HPP


#include "Application/IPlayer.hpp"

#include <memory>
#include <string>

#include "Domain/IBoard.hpp"
#include "Domain/Stone.hpp"


namespace Gomoku
{
namespace Interface
{


class HumanPlayer : public Application::IPlayer
{
public:
    HumanPlayer(
            const std::string& name_,
            std::shared_ptr<Domain::IBoard> board_,
            const Domain::Stone& stone_);

    void performMove() override;

private:
    int readX();
    int readY();

    bool validMove(int x, int y);

    const std::string name;
    std::shared_ptr<Domain::IBoard> board;
    const Domain::Stone stone;
};


} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_INTERFACE_HUMANPLAYER_HPP
