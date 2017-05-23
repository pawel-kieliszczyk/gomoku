#include "application/artificial_intelligence/MiniMaxPlayerFactory.hpp"

#include <memory>

#include "application/artificial_intelligence/AdjacentMoveCandidatesSelector.hpp"
#include "application/artificial_intelligence/MiniMaxPlayer.hpp"


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
