#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYERFACTORY_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYERFACTORY_HPP


#include "gomoku/application/iplayer_factory.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class MiniMaxPlayerFactory : public IPlayerFactory
{
public:
    std::shared_ptr<IPlayer> create(
            std::shared_ptr<Domain::IBoard> board,
            const Domain::Stone& stone) override;
};


} // namespace ArtificialIntelligence
} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MINIMAXPLAYERFACTORY_HPP
