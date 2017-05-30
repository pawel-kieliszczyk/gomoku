#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREESEARCHPLAYER_H
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREESEARCHPLAYER_H


#include "gomoku/application/iplayer.h"

#include <memory>

#include "gomoku/application/artificial_intelligence/imove_candidates_selector.h"
#include "gomoku/application/artificial_intelligence/monte_carlo_tree.h"
#include "gomoku/domain/iboard.h"
#include "gomoku/domain/stone.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class MonteCarloTreeSearchPlayer : public IPlayer
{
public:
    MonteCarloTreeSearchPlayer(
            std::shared_ptr<Domain::IBoard> board_,
            const Domain::Stone& stone_,
            std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_);

    void performMove() override;

private:
    static constexpr int simulationsLimit = 500;

    std::shared_ptr<Domain::IBoard> board;
    const Domain::Stone stone;
    std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector;

    MonteCarloTree monteCarloTree;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREESEARCHPLAYER_H
