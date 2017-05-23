#include "interface/human_player_factory.h"

#include <memory>

#include "interface/human_player.h"


namespace Gomoku
{
namespace Interface
{


HumanPlayerFactory::HumanPlayerFactory(const std::string& playerName_) : playerName(playerName_)
{
}


std::shared_ptr<Application::IPlayer> HumanPlayerFactory::create(
        std::shared_ptr<Domain::IBoard> board,
        const Domain::Stone& stone)
{
    return std::make_shared<HumanPlayer>(playerName, board, stone);
}


} // namespace Interface
} // namespace Gomoku
