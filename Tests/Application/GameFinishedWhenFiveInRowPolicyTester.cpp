#include <memory>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Application/GameFinishedWhenFiveInRowPolicy.hpp"
#include "Domain/Board.hpp"
#include "Domain/Stone.hpp"


namespace gt = testing;


namespace Gomoku
{
namespace Application
{
namespace Testing
{


struct GameFinishedWhenFiveInRowPolicyTester : public gt::Test
{
    // mocks:
    std::shared_ptr<Domain::Board> board = std::make_shared<Domain::Board>();

    // tested class:
    GameFinishedWhenFiveInRowPolicy policy{board};
};


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsFiveVerticallyIfFifthStonePutAtTheEnd)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(7, 8, Domain::Stone::Black);
    board->putStone(7, 9, Domain::Stone::Black);
    board->putStone(7, 10, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(7, 11, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsFiveVerticallyIfFifthStonePutAtTheBeginning)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(7, 8, Domain::Stone::Black);
    board->putStone(7, 9, Domain::Stone::Black);
    board->putStone(7, 10, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(7, 6, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsFiveVerticallyIfFifthStonePutInTheMiddle)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(7, 8, Domain::Stone::Black);
    board->putStone(7, 10, Domain::Stone::Black);
    board->putStone(7, 11, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(7, 9, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsFiveHorizontallyIfFifthStonePutAtTheEnd)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 7, Domain::Stone::Black);
    board->putStone(9, 7, Domain::Stone::Black);
    board->putStone(10, 7, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(11, 7, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsFiveHorizontallyIfFifthStonePutAtTheBeginning)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 7, Domain::Stone::Black);
    board->putStone(9, 7, Domain::Stone::Black);
    board->putStone(10, 7, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(6, 7, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsFiveHorizontallyIfFifthStonePutAtTheMiddle)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 7, Domain::Stone::Black);
    board->putStone(10, 7, Domain::Stone::Black);
    board->putStone(11, 7, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(9, 7, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsDiagonalOneIfFifthStonePutAtTheEnd)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 8, Domain::Stone::Black);
    board->putStone(9, 9, Domain::Stone::Black);
    board->putStone(10, 10, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(11, 11, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsDiagonalOneIfFifthStonePutAtTheBeginning)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 8, Domain::Stone::Black);
    board->putStone(9, 9, Domain::Stone::Black);
    board->putStone(10, 10, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(6, 6, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsDiagonalOneIfFifthStonePutInTheMiddle)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 8, Domain::Stone::Black);
    board->putStone(10, 10, Domain::Stone::Black);
    board->putStone(11, 11, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(9, 9, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsDiagonalTwoIfFifthStonePutAtTheEnd)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 6, Domain::Stone::Black);
    board->putStone(9, 5, Domain::Stone::Black);
    board->putStone(10, 4, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(11, 3, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsDiagonalTwoIfFifthStonePutAtTheBeginning)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 6, Domain::Stone::Black);
    board->putStone(9, 5, Domain::Stone::Black);
    board->putStone(10, 4, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(6, 8, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTester, testsDiagonalTwoIfFifthStonePutInTheMiddle)
{
    // given
    board->putStone(7, 7, Domain::Stone::Black);
    board->putStone(8, 6, Domain::Stone::Black);
    board->putStone(10, 4, Domain::Stone::Black);
    board->putStone(11, 3, Domain::Stone::Black);

    // when & then
    EXPECT_EQ(false, policy.isFinished());

    // when
    board->putStone(9, 5, Domain::Stone::Black);

    // then
    EXPECT_EQ(true, policy.isFinished());
}


} // namespace Testing
} // namespace Application
} // namespace Gomoku