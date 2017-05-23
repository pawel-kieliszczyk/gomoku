#ifndef GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICYFACTORY_HPP
#define GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICYFACTORY_HPP


#include "application/igame_finished_policy_factory.h"


namespace Gomoku
{
namespace Application
{


class GameFinishedWhenFiveInRowPolicyFactory : public IGameFinishedPolicyFactory
{
public:
    std::shared_ptr<IGameFinishedPolicy> create(std::shared_ptr<Domain::IBoard> board) override;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICYFACTORY_HPP
