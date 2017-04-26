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
    MOCK_METHOD0(getSize, int());
    MOCK_METHOD2(putWhiteDot, void(int /*x*/, int /*y*/));
    MOCK_METHOD2(putBlackDot, void(int /*x*/, int /*y*/));
    MOCK_METHOD2(getValue, BoardValue(int /*x*/, int /*y*/));
    MOCK_METHOD0(clear, void());
};


} // namespace Testing
} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP
