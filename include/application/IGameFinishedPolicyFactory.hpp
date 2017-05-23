#ifndef GOMOKU_APPLICATION_IGAMEFINISHEDPOLICYFACTORY_HPP
#define GOMOKU_APPLICATION_IGAMEFINISHEDPOLICYFACTORY_HPP


#include <memory>

#include "domain/IBoard.hpp"

#include "IGameFinishedPolicy.hpp"


namespace Gomoku
{
namespace Application
{


class IGameFinishedPolicyFactory
{
public:
    virtual ~IGameFinishedPolicyFactory() = default;

    virtual std::shared_ptr<IGameFinishedPolicy> create(std::shared_ptr<Domain::IBoard> board) = 0;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_IGAMEFINISHEDPOLICYFACTORY_HPP
