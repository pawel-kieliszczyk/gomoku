#ifndef GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYMOCK_HPP
#define GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYMOCK_HPP


#include <gmock/gmock.h>

#include "gomoku/application/igame_finished_policy.h"


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
    MOCK_CONST_METHOD0(getWinner, std::experimental::optional<Domain::Stone>());
};


} // namespace Testing
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_TESTING_GAMEFINISHEDPOLICYMOCK_HPP
