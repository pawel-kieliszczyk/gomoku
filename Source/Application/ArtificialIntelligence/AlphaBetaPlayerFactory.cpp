#include "Application/ArtificialIntelligence/AlphaBetaPlayerFactory.hpp"

#include <memory>

#include "Application/ArtificialIntelligence/AdjacentMoveCandidatesSelector.hpp"
#include "Application/ArtificialIntelligence/AlphaBetaPlayer.hpp"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


std::shared_ptr<IPlayer> AlphaBetaPlayerFactory::create(
            std::shared_ptr<Domain::IBoard> board,
            const Domain::Stone& stone)
{
    auto moveCandidatesSelector = std::make_shared<AdjacentMoveCandidatesSelector>();
    return std::make_shared<AlphaBetaPlayer>(board, stone, moveCandidatesSelector);
}


} // namespace ArtificialIntelligence
} // namespace Interface
} // namespace Gomoku
