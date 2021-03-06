#include <memory>
#include <stdexcept>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "gomoku/domain/board.h"
#include "gomoku/domain/stone.h"

#include "gomoku/mocks/domain/board_observer_mock.h"


namespace gt = testing;


namespace Gomoku
{
namespace Domain
{
namespace Testing
{


struct BoardTest : public gt::Test
{
    // mocks:
    std::shared_ptr<BoardObserverMock> boardObserverMock1 = std::make_shared<gt::StrictMock<BoardObserverMock>>();
    std::shared_ptr<BoardObserverMock> boardObserverMock2 = std::make_shared<gt::StrictMock<BoardObserverMock>>();

    // tested class:
    Board board;
};


TEST_F(BoardTest, testsGetSize)
{
    EXPECT_EQ(15, board.getSize());
}


TEST_F(BoardTest, testsValuesOfEmptyBoard)
{
    // when & then
    for(int i = 0; i < board.getSize(); ++i)
        for(int j = 0; j < board.getSize(); ++j)
            EXPECT_EQ(false, board.hasStone(i, j));
}


TEST_F(BoardTest, testsPuttingBlackStone)
{
    // when
    board.putStone(2, 3, Stone::Black);

    // then
    EXPECT_EQ(true, board.hasStone(2, 3));
    EXPECT_EQ(Stone::Black, board.getStone(2, 3));
}


TEST_F(BoardTest, testsPuttingWhiteStone)
{
    // when
    board.putStone(2, 3, Stone::White);

    // then
    EXPECT_EQ(true, board.hasStone(2, 3));
    EXPECT_EQ(Stone::White, board.getStone(2, 3));
}


TEST_F(BoardTest, testsRemovingStone)
{
    // given
    board.putStone(2, 3, Stone::Black);
    board.putStone(7, 8, Stone::White);

    // when
    board.removeStone(2, 3);

    // then
    EXPECT_EQ(false, board.hasStone(2, 3));

    ASSERT_EQ(true, board.hasStone(7, 8));
    EXPECT_EQ(Stone::White, board.getStone(7, 8));
}


TEST_F(BoardTest, testsClearingBoard)
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


TEST_F(BoardTest, testsExceptionWhenPuttingStoneOutOfRange)
{
    // when & then
    EXPECT_THROW(board.putStone(-1, 0, Stone::Black), std::out_of_range);
    EXPECT_THROW(board.putStone(0, -1, Stone::White), std::out_of_range);
    EXPECT_THROW(board.putStone(board.getSize(), 0, Stone::Black), std::out_of_range);
    EXPECT_THROW(board.putStone(0, board.getSize(), Stone::White), std::out_of_range);
}


TEST_F(BoardTest, testsExceptionWhenPuttingTwoStonesOnTheSamePlace)
{
    // given
    board.putStone(4, 5, Stone::Black);

    // when and then
    EXPECT_THROW(board.putStone(4, 5, Stone::Black), std::runtime_error);
    EXPECT_THROW(board.putStone(4, 5, Stone::White), std::runtime_error);
}


TEST_F(BoardTest, testsNotifyingObserversAfterStonePut)
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


TEST_F(BoardTest, testsNotifyingObserversAfterBoardCleared)
{
    // given
    board.addObserver(*boardObserverMock1);
    board.addObserver(*boardObserverMock2);

    // expect
    EXPECT_CALL(*boardObserverMock1, onBoardCleared());
    EXPECT_CALL(*boardObserverMock2, onBoardCleared());

    // when & then
    board.clear();
}


} // namespace Testing
} // namespace Domain
} // namespace Gomoku
