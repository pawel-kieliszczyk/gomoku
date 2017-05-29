#ifndef GOMOKU_APPLICATION_IGAMEFINISHEDPOLICY_HPP
#define GOMOKU_APPLICATION_IGAMEFINISHEDPOLICY_HPP


#include <experimental/optional>

#include "gomoku/domain/stone.h"


namespace Gomoku
{
namespace Application
{


class IGameFinishedPolicy
{
public:
    virtual ~IGameFinishedPolicy() = default;

    virtual bool isFinished() const = 0;
    virtual std::experimental::optional<Domain::Stone> getWinner() const = 0;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_IGAMEFINISHEDPOLICY_HPP
