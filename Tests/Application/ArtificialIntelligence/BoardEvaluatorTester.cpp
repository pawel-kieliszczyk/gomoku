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
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 3));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 5));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesFiveWhiteStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(2, 3, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);
    board->putStone(2, 5, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 3));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 5));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesFiveBlackStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 2, Domain::Stone::Black);
    board->putStone(4, 2, Domain::Stone::Black);
    board->putStone(5, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 3, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 5, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesFiveWhiteStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 2, Domain::Stone::White);
    board->putStone(4, 2, Domain::Stone::White);
    board->putStone(5, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 3, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 5, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesFiveBlackStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);
    board->putStone(4, 4, Domain::Stone::Black);
    board->putStone(5, 5, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 4, 4));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 5, 5));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);
    board->putStone(4, 2, Domain::Stone::Black);
    board->putStone(5, 1, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
    EXPECT_EQ(BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 5, 1));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesFiveWhiteStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);
    board->putStone(4, 4, Domain::Stone::White);
    board->putStone(5, 5, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 4, 4));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 5, 5));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);
    board->putStone(4, 2, Domain::Stone::White);
    board->putStone(5, 1, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
    EXPECT_EQ(-BoardEvaluator::FIVE_STONES_WEIGHT, evaluator.evaluate(board, 5, 1));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenFourBlackStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(2, 3, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 3));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenFourWhiteStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(2, 3, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 3));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenFourBlackStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 2, Domain::Stone::Black);
    board->putStone(4, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 3, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenFourWhiteStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 2, Domain::Stone::White);
    board->putStone(4, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 3, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenFourBlackStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);
    board->putStone(4, 4, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 4, 4));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);
    board->putStone(4, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenFourWhiteStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);
    board->putStone(4, 4, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 4, 4));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);
    board->putStone(4, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
    EXPECT_EQ(-BoardEvaluator::OPEN_FOUR_STONES_WEIGHT, evaluator.evaluate(board, 4, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenThreeBlackStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(2, 3, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 3));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenThreeWhiteStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(2, 3, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 3));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenThreeBlackStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 3, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenThreeWhiteStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 3, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenThreeBlackStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);
    board->putStone(3, 3, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenThreeWhiteStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);
    board->putStone(3, 3, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
    EXPECT_EQ(-BoardEvaluator::OPEN_THREE_STONES_WEIGHT, evaluator.evaluate(board, 3, 3));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenTwoBlackStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenTwoWhiteStonesHorizontally)
{
    // when
    board->putStone(2, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 1));
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenTwoBlackStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenTwoWhiteStonesVertically)
{
    // when
    board->putStone(1, 2, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 1, 2));
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenTwoBlackStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::Black);
    board->putStone(2, 2, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::Black);
    board->putStone(2, 4, Domain::Stone::Black);

    // then
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
}


TEST_F(BoardEvaluatorTester, testsLastMoveMakesOpenTwoWhiteStonesDiagonally)
{
    // when
    board->putStone(1, 1, Domain::Stone::White);
    board->putStone(2, 2, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 1, 1));
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 2));

    // given
    board->clear();

    // when
    board->putStone(1, 5, Domain::Stone::White);
    board->putStone(2, 4, Domain::Stone::White);

    // then
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 1, 5));
    EXPECT_EQ(-BoardEvaluator::OPEN_TWO_STONES_WEIGHT, evaluator.evaluate(board, 2, 4));
}


} // namespace Testing
} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
