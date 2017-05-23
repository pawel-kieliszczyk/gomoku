#include "application/artificial_intelligence/AlphaBetaPlayerFactory.hpp"

#include <memory>

#include "application/artificial_intelligence/AdjacentMoveCandidatesSelector.hpp"
#include "application/artificial_intelligence/AlphaBetaPlayer.hpp"


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
