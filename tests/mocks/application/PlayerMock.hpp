#ifndef GOMOKU_APPLICATION_TESTING_PLAYERMOCK_HPP
#define GOMOKU_APPLICATION_TESTING_PLAYERMOCK_HPP


#include <gmock/gmock.h>

#include "application/iplayer.h"


namespace Gomoku
{
namespace Application
{
namespace Testing
{


class PlayerMock : public IPlayer
{
public:
    MOCK_METHOD0(performMove, void());
};


} // namespace Testing
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_TESTING_PLAYERMOCK_HPP
