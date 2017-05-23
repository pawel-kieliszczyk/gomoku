#ifndef GOMOKU_DOMAIN_BOARDOBSERVERMOCK_HPP
#define GOMOKU_DOMAIN_BOARDOBSERVERMOCK_HPP


#include <gmock/gmock.h>

#include "domain/IBoardObserver.hpp"


namespace Gomoku
{
namespace Domain
{
namespace Testing
{


class BoardObserverMock : public IBoardObserver
{
public:
    MOCK_METHOD2(onStonePutAt, void(int /*x*/, int /*y*/));
    MOCK_METHOD0(onBoardCleared, void());
};


} // namespace Testing
} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_BOARDOBSERVERMOCK_HPP
