#include <algorithm>
#include <iterator>
#include <memory>

#include <gtest/gtest.h>

#include "application/artificial_intelligence/adjacent_move_candidates_selector.h"
#include "domain/board.h"


namespace gt = testing;


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{
namespace Testing
{


struct AdjacentMoveCandidatesSelectorTest : public gt::Test
{
    // mocks:
    std::shared_ptr<Domain::IBoard> board = std::make_shared<Domain::Board>();

    // tested class:
    AdjacentMoveCandidatesSelector selector;

    bool contains(const std::vector<std::pair<int, int>>& moves, const std::pair<int, int>& move)
    {
        return (std::find(std::begin(moves), std::end(moves), move) != std::end(moves));
    }
};


/**
 * Tested situation:
 *  ------------------------------
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |        x                     |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 *  ------------------------------
 */
TEST_F(AdjacentMoveCandidatesSelectorTest, testSelectingWithOneStoneOnTheBoard)
{
    // given
    board->putStone(5, 5, Domain::Stone::Black);

    // when & then
    const auto selectedMoves = selector.selectMoves(board);

    ASSERT_EQ(8, selectedMoves.size());

    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 6)));
}


/**
 * Tested situation:
 *  ------------------------------
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |        x                     |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                    x         |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 *  ------------------------------
 */
TEST_F(AdjacentMoveCandidatesSelectorTest, testSelectingWithTwoDistantStonesOnTheBoard)
{
    // given
    board->putStone(5, 5, Domain::Stone::Black);
    board->putStone(10, 10, Domain::Stone::Black);

    // when & then
    const auto selectedMoves = selector.selectMoves(board);

    ASSERT_EQ(16, selectedMoves.size());

    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 6)));

    EXPECT_TRUE(contains(selectedMoves, std::make_pair(9, 9)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(9, 10)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(9, 11)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(10, 9)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(10, 11)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(11, 9)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(11, 10)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(11, 11)));
}


/**
 * Tested situation:
 *  ------------------------------
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |        x                     |
 * |         x                    |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 *  ------------------------------
 */
TEST_F(AdjacentMoveCandidatesSelectorTest, testSelectingWithTwoCloseStonesOnTheBoard)
{
    // given
    board->putStone(5, 5, Domain::Stone::Black);
    board->putStone(6, 6, Domain::Stone::Black);

    // when & then
    const auto selectedMoves = selector.selectMoves(board);

    ASSERT_EQ(12, selectedMoves.size());

    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 5)));
    // skipping (6, 6)

    // skipping (5, 5)
    // skipping (5, 6)
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 7)));
    // skipping (6, 5)
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 7)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(7, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(7, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(7, 7)));
}


/**
 * Tested situation:
 *  ------------------------------
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |        x                     |
 * |        x                     |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 * |                              |
 *  ------------------------------
 */
TEST_F(AdjacentMoveCandidatesSelectorTest, testSelectingWithTwoVeryCloseStonesOnTheBoard)
{
    // given
    board->putStone(5, 5, Domain::Stone::Black);
    board->putStone(6, 5, Domain::Stone::Black);

    // when & then
    const auto selectedMoves = selector.selectMoves(board);

    ASSERT_EQ(10, selectedMoves.size());

    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(4, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(5, 6)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 4)));
    // skipping (6, 5)
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(6, 6)));

    // skipping (5, 4)
    // skipping (5, 5)
    // skipping (5, 6)
    // skipping (6, 4)
    // skipping (6, 6)
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(7, 4)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(7, 5)));
    EXPECT_TRUE(contains(selectedMoves, std::make_pair(7, 6)));
}


} // namespace Testing
} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
