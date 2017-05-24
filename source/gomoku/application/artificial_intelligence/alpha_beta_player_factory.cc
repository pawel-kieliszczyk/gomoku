#include "gomoku/application/artificial_intelligence/alpha_beta_player_factory.h"

#include <memory>

#include "gomoku/application/artificial_intelligence/adjacent_move_candidates_selector.h"
#include "gomoku/application/artificial_intelligence/alpha_beta_player.h"


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
