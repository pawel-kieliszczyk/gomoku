#ifndef GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYMOCK_HPP
#define GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYMOCK_HPP


#include <gmock/gmock.h>

#include "Application/IGameFinishedPolicy.hpp"


namespace Gomoku
{
namespace Application
{
namespace Testing
{


class GameFinishedPolicyMock : public IGameFinishedPolicy
{
public:
    MOCK_CONST_METHOD0(isFinished, bool());
};


} // namespace Testing
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYMOCK_HPP
