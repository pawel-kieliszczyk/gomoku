#ifndef GOMOKU_APPLICATION_IPLAYERFACTORY_HPP
#define GOMOKU_APPLICATION_IPLAYERFACTORY_HPP


#include <memory>

#include "domain/IBoard.hpp"
#include "domain/Stone.hpp"

#include "IPlayer.hpp"


namespace Gomoku
{
namespace Application
{


class IPlayerFactory
{
public:
    virtual ~IPlayerFactory() = default;

    virtual std::shared_ptr<IPlayer> create(std::shared_ptr<Domain::IBoard> board, const Domain::Stone& stone) = 0;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_IPLAYERFACTORY_HPP
