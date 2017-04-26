#include <memory>
#include <stdexcept>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Application/GameController.hpp"

#include "Mocks/Domain/BoardMock.hpp"


namespace gt = testing;


namespace Gomoku
{
namespace Application
{
namespace Testing
{

struct GameControllerTester : public gt::Test
{
    // mocks:
    std::shared_ptr<Domain::Testing::BoardMock> boardMock = std::make_shared<Domain::Testing::BoardMock>();

    // tested class:
    GameController controller{boardMock};
};


TEST_F(GameControllerTester, testsStartingNewGame)
{
    // expect
    EXPECT_CALL(*boardMock, clear());

    // when & then
    controller.startNewGame();
}


TEST_F(GameControllerTester, testsMakingFirstMoveAsBlack)
{
    // expect
    EXPECT_CALL(*boardMock, putBlackDot(2, 3));

    // when & then
    controller.moveBlack(2, 3);
}


TEST_F(GameControllerTester, testsMakingFirstMoveAsWhite)
{
    // when & then
    EXPECT_THROW(controller.moveWhite(4, 5), std::runtime_error);
}


TEST_F(GameControllerTester, testsMakingSecondMoveAsBlack)
{
    // given
    EXPECT_CALL(*boardMock, putBlackDot(2, 3));
    controller.moveBlack(2, 3);

    // when & then
    EXPECT_THROW(controller.moveBlack(4, 5), std::runtime_error);
}


TEST_F(GameControllerTester, testsMakingSecondMoveAsWhite)
{
    // given
    EXPECT_CALL(*boardMock, putBlackDot(2, 3));
    controller.moveBlack(2, 3);

    // expect
    EXPECT_CALL(*boardMock, putWhiteDot(4, 5));

    // when & then
    controller.moveWhite(4, 5);
}


} // namespace Testing
} // namespace Application
} // namespace Gomoku
