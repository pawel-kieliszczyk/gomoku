#include <memory>
#include <stdexcept>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Domain/Board.hpp"
#include "Domain/Stone.hpp"

#include "Mocks/Domain/BoardObserverMock.hpp"


namespace gt = testing;


namespace Gomoku
{
namespace Domain
{
namespace Testing
{


struct BoardTester : public gt::Test
{
    // mocks:
    std::shared_ptr<BoardObserverMock> boardObserverMock1 = std::make_shared<gt::StrictMock<BoardObserverMock>>();
    std::shared_ptr<BoardObserverMock> boardObserverMock2 = std::make_shared<gt::StrictMock<BoardObserverMock>>();

    // tested class:
    Board board;
};


TEST_F(BoardTester, testsGetSize)
{
    EXPECT_EQ(15, board.getSize());
}


TEST_F(BoardTester, testsValuesOfEmptyBoard)
{
    // when & then
    for(int i = 0; i < board.getSize(); ++i)
        for(int j = 0; j < board.getSize(); ++j)
            EXPECT_EQ(false, board.hasStone(i, j));
}


TEST_F(BoardTester, testsPuttingBlackStone)
{
    // when
    board.putStone(2, 3, Stone::Black);

    // then
    EXPECT_EQ(true, board.hasStone(2, 3));
    EXPECT_EQ(Stone::Black, board.getStone(2, 3));
}


TEST_F(BoardTester, testsPuttingWhiteStone)
{
    // when
    board.putStone(2, 3, Stone::White);

    // then
    EXPECT_EQ(true, board.hasStone(2, 3));
    EXPECT_EQ(Stone::White, board.getStone(2, 3));
}


TEST_F(BoardTester, testsClearingBoard)
{
    // given
    board.putStone(7, 8, Stone::Black);
    board.putStone(2, 3, Stone::White);

    // when
    board.clear();

    // then
    EXPECT_EQ(false, board.hasStone(7, 8));
    EXPECT_EQ(false, board.hasStone(2, 3));
}


TEST_F(BoardTester, testsExceptionWhenPuttingStoneOutOfRange)
{
    // when & then
    EXPECT_THROW(board.putStone(-1, 0, Stone::Black), std::out_of_range);
    EXPECT_THROW(board.putStone(0, -1, Stone::White), std::out_of_range);
    EXPECT_THROW(board.putStone(board.getSize(), 0, Stone::Black), std::out_of_range);
    EXPECT_THROW(board.putStone(0, board.getSize(), Stone::White), std::out_of_range);
}


TEST_F(BoardTester, testsExceptionWhenPuttingTwoStonesOnTheSamePlace)
{
    // given
    board.putStone(4, 5, Stone::Black);

    // when and then
    EXPECT_THROW(board.putStone(4, 5, Stone::Black), std::runtime_error);
    EXPECT_THROW(board.putStone(4, 5, Stone::White), std::runtime_error);
}


TEST_F(BoardTester, testsNotifyingObservers)
{
    // given
    board.addObserver(*boardObserverMock1);
    board.addObserver(*boardObserverMock2);

    // expect
    EXPECT_CALL(*boardObserverMock1, onStonePutAt(2, 3));
    EXPECT_CALL(*boardObserverMock2, onStonePutAt(2, 3));

    // when & then
    board.putStone(2, 3, Stone::Black);

    // expect
    EXPECT_CALL(*boardObserverMock1, onStonePutAt(8, 1));
    EXPECT_CALL(*boardObserverMock2, onStonePutAt(8, 1));

    // when & then
    board.putStone(8, 1, Stone::White);
}


} // namespace Testing
} // namespace Domain
} // namespace Gomoku
