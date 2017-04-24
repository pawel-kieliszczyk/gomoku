#include <gtest/gtest.h>

#include "Domain/Board.hpp"


namespace gt = testing;


namespace Gomoku
{
namespace Domain
{
namespace Testing
{


struct BoardTester : public gt::Test
{
    // tested class:
    Board board;
};


TEST_F(BoardTester, testsGetSize)
{
    EXPECT_EQ(15, board.getSize());
}


TEST_F(BoardTester, testsValuesOfEmptyBoard)
{
    for(int i = 0; i < board.getSize(); ++i)
        for(int j = 0; j < board.getSize(); ++j)
            EXPECT_EQ(Board::Value::Blank, board.getValue(i, j));
}


TEST_F(BoardTester, testsPuttingWhiteDot)
{
    // when
    board.putWhiteDot(2, 3);

    // then
    EXPECT_EQ(Board::Value::WhiteDot, board.getValue(2, 3));
}


TEST_F(BoardTester, testsPuttingBlackDot)
{
    // when
    board.putBlackDot(2, 3);

    // then
    EXPECT_EQ(Board::Value::BlackDot, board.getValue(2, 3));
}


} // namespace Testing
} // namespace Domain
} // namespace Gomoku
