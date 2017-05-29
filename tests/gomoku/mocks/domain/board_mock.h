#ifndef GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP
#define GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP


#include <gmock/gmock.h>

#include "gomoku/domain/iboard.h"


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
    MOCK_METHOD2(removeStone, void(int /*x*/, int /*y*/));
    MOCK_CONST_METHOD0(getStonesCount, int());
    MOCK_CONST_METHOD2(hasStone, bool(int /*x*/, int /*y*/));
    MOCK_METHOD0(clear, void());
    MOCK_METHOD1(addObserver, void(IBoardObserver& /*observer*/));
    MOCK_METHOD1(removeObserver, void(IBoardObserver& /*observer*/));
};


} // namespace Testing
} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_TESTING_BOARDMOCK_HPP
