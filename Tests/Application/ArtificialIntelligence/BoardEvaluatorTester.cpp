#include <memory>

#include <gtest/gtest.h>

#include "Application/ArtificialIntelligence/BoardEvaluator.hpp"
#include "Domain/Board.hpp"


namespace gt = testing;


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{
namespace Testing
{


struct BoardEvaluatorTester : public gt::Test
{
    // mocks:
    std::shared_ptr<Domain::IBoard> board = std::make_shared<Domain::Board>();

    // tested class:
    BoardEvaluator evaluator;
};


TEST_F(BoardEvaluatorTester, testsFiveBlackStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(2, 3, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);
    board->putStone(2, 5, Domain::Stone::Black);

    // then
    EXPECT_EQ(std::numeric_limits<int>::max(), evaluator.evaluate(board));
}


TEST_F(BoardEvaluatorTester, testsFiveWhiteStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(2, 3, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);
    board->putStone(2, 5, Domain::Stone::White);

    // then
    EXPECT_EQ(std::numeric_limits<int>::min(), evaluator.evaluate(board));
}


TEST_F(BoardEvaluatorTester, testsFiveBlackStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 2, Domain::Stone::Black);
    board->putStone(4, 2, Domain::Stone::Black);
    board->putStone(5, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(std::numeric_limits<int>::max(), evaluator.evaluate(board));
}


TEST_F(BoardEvaluatorTester, testsFiveWhiteStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 2, Domain::Stone::White);
    board->putStone(4, 2, Domain::Stone::White);
    board->putStone(5, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(std::numeric_limits<int>::min(), evaluator.evaluate(board));
}


TEST_F(BoardEvaluatorTester, testsFiveBlackStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);
    board->putStone(4, 4, Domain::Stone::Black);
    board->putStone(5, 5, Domain::Stone::Black);

    // then
    EXPECT_EQ(std::numeric_limits<int>::max(), evaluator.evaluate(board));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);
    board->putStone(4, 2, Domain::Stone::Black);
    board->putStone(5, 1, Domain::Stone::Black);

    // then
    EXPECT_EQ(std::numeric_limits<int>::max(), evaluator.evaluate(board));
}


TEST_F(BoardEvaluatorTester, testsFiveWhiteStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);
    board->putStone(4, 4, Domain::Stone::White);
    board->putStone(5, 5, Domain::Stone::White);

    // then
    EXPECT_EQ(std::numeric_limits<int>::min(), evaluator.evaluate(board));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);
    board->putStone(4, 2, Domain::Stone::White);
    board->putStone(5, 1, Domain::Stone::White);

    // then
    EXPECT_EQ(std::numeric_limits<int>::min(), evaluator.evaluate(board));
}


} // namespace Testing
} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
