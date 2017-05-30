#ifndef GOMOKU_INTERFACE_HUMANPLAYERFACTORY_HPP
#define GOMOKU_INTERFACE_HUMANPLAYERFACTORY_HPP


#include "gomoku/application/iplayer_factory.h"

#include <string>


namespace Gomoku
{
namespace Interface
{


class HumanPlayerFactory : public Application::IPlayerFactory
{
public:
    HumanPlayerFactory(const std::string& playerName_);

    std::shared_ptr<Application::IPlayer> create(
            std::shared_ptr<Domain::IBoard> board,
            const Domain::Stone& stone) override;

private:
    const std::string playerName;
};


} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_INTERFACE_HUMANPLAYERFACTORY_HPP
