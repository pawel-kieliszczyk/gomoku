#include <memory>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "application/game_finished_when_five_in_row_policy.h"
#include "domain/board.h"
#include "domain/stone.h"


namespace gt = testing;


namespace Gomoku
{
namespace Application
{
namespace Testing
{


struct GameFinishedWhenFiveInRowPolicyTest : public gt::Test
{
    // mocks:
    std::shared_ptr<Domain::Board> board = std::make_shared<Domain::Board>();

    // tested class:
    GameFinishedWhenFiveInRowPolicy policy{board};
};


/**
 * Filling the board with the following pattern:
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 * o o o x x x o o o x x x o o o
 * x x x o o o x x x o o o x x x
 *
 */
TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsMakingAllPossibleMoves)
{
    const int limit = 3;
    int counter = 0;
    Domain::Stone nextStone = Domain::Stone::Black;

    // when (board fillout without last stone)
    for(int x = 0; x < board->getSize(); ++x)
    {
        for(int y = 0; y < board->getSize(); ++y)
        {
            if((x == board->getSize() - 1) && (y == board->getSize() - 1))
                break;

            board->putStone(x, y, nextStone);

            ++counter;
            if(counter == limit)
            {
                nextStone = ((nextStone == Domain::Stone::Black) ? Domain::Stone::White : Domain::Stone::Black);
                counter = 0;
            }
        }
    }

    // then
    EXPECT_FALSE(policy.isFinished());

    // when
    board->putStone(board->getSize() - 1, board->getSize() - 1, nextStone);

    // then
    EXPECT_TRUE(policy.isFinished());
}


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsFiveVerticallyIfFifthStonePutAtTheEnd)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsFiveVerticallyIfFifthStonePutAtTheBeginning)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsFiveVerticallyIfFifthStonePutInTheMiddle)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsFiveHorizontallyIfFifthStonePutAtTheEnd)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsFiveHorizontallyIfFifthStonePutAtTheBeginning)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsFiveHorizontallyIfFifthStonePutAtTheMiddle)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsDiagonalOneIfFifthStonePutAtTheEnd)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsDiagonalOneIfFifthStonePutAtTheBeginning)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsDiagonalOneIfFifthStonePutInTheMiddle)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsDiagonalTwoIfFifthStonePutAtTheEnd)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsDiagonalTwoIfFifthStonePutAtTheBeginning)
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


TEST_F(GameFinishedWhenFiveInRowPolicyTest, testsDiagonalTwoIfFifthStonePutInTheMiddle)
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
