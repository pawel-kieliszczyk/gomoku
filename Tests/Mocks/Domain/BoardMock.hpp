#ifndef GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP
#define GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP


#include <gmock/gmock.h>

#include "Domain/IBoard.hpp"


namespace Gomoku
{
namespace Domain
{
namespace Testing
{


class BoardMock : public IBoard
{
public:
    MOCK_CONST_METHOD0(getSize, int());
    MOCK_METHOD3(putStone, void(int /*x*/, int /*y*/, const Stone& /*stone*/));
    MOCK_CONST_METHOD2(getStone, Stone(int /*x*/, int /*y*/));
    MOCK_CONST_METHOD2(hasStone, bool(int /*x*/, int /*y*/));
    MOCK_METHOD0(clear, void());
};


} // namespace Testing
} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP
