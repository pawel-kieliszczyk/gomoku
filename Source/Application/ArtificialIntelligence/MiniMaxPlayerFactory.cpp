#include "Application/ArtificialIntelligence/MiniMaxPlayerFactory.hpp"

#include <memory>

#include "Application/ArtificialIntelligence/AdjacentMoveCandidatesSelector.hpp"
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
    auto moveCandidatesSelector = std::make_shared<AdjacentMoveCandidatesSelector>();
    return std::make_shared<MiniMaxPlayer>(board, stone, moveCandidatesSelector);
}


} // namespace ArtificialIntelligence
} // namespace Interface
} // namespace Gomoku
