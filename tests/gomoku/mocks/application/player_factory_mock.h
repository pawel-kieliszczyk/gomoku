#ifndef GOMOKU_APPLICATION_TESTING_PLAYERFACTORYMOCK_HPP
#define GOMOKU_APPLICATION_TESTING_PLAYERFACTORYMOCK_HPP


#include <gmock/gmock.h>

#include "gomoku/application/iplayer_factory.h"


namespace Gomoku
{
namespace Application
{
namespace Testing
{


class PlayerFactoryMock : public IPlayerFactory
{
public:
    MOCK_METHOD2(create, std::shared_ptr<IPlayer>(std::shared_ptr<Domain::IBoard> /*board*/, const Domain::Stone& /*stone*/));
};


} // namespace Testing
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_TESTING_PLAYERFACTORYMOCK_HPP
