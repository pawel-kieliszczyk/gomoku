#include "Application/ArtificialIntelligence/MiniMaxPlayerFactory.hpp"

#include <memory>

#include "Application/ArtificialIntelligence/MiniMaxPlayer.hpp"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


std::shared_ptr<IPlayer> MiniMaxPlayerFactory::create(
            std::shared_ptr<Domain::IBoard> board,
            const Domain::Stone& stone)
{
    return std::make_shared<MiniMaxPlayer>(board, stone);
}


} // namespace ArtificialIntelligence
} // namespace Interface
} // namespace Gomoku
