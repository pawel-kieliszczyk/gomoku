#ifndef GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYFACTORYMOCK_HPP
#define GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYFACTORYMOCK_HPP


#include <gmock/gmock.h>

#include "Application/IGameFinishedPolicyFactory.hpp"


namespace Gomoku
{
namespace Application
{
namespace Testing
{


class GameFinishedPolicyFactoryMock : public IGameFinishedPolicyFactory
{
public:
    MOCK_METHOD1(create, std::shared_ptr<IGameFinishedPolicy>(std::shared_ptr<Domain::IBoard> /*board*/));
};


} // namespace Testing
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYFACTORYMOCK_HPP
