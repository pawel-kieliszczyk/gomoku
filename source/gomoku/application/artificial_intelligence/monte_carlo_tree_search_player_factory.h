#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREESEARCHPLAYERFACTORY_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREESEARCHPLAYERFACTORY_HPP


#include "gomoku/application/iplayer_factory.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class MonteCarloTreeSearchPlayerFactory : public IPlayerFactory
{
public:
    std::shared_ptr<IPlayer> create(
            std::shared_ptr<Domain::IBoard> board,
            const Domain::Stone& stone) override;
};


} // namespace ArtificialIntelligence
} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREESEARCHPLAYERFACTORY_HPP
