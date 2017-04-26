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
    std::shared_ptr<Domain::Testing::BoardMock> boardMock = std::make_shared<gt::StrictMock<Domain::Testing::BoardMock>>();

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
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));

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
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));
    controller.moveBlack(2, 3);

    // when & then
    EXPECT_THROW(controller.moveBlack(4, 5), std::runtime_error);
}


TEST_F(GameControllerTester, testsMakingSecondMoveAsWhite)
{
    // given
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));
    controller.moveBlack(2, 3);

    // expect
    EXPECT_CALL(*boardMock, putStone(4, 5, Domain::Stone::White));

    // when & then
    controller.moveWhite(4, 5);
}


TEST_F(GameControllerTester, testsMakingThirdMoveAsBlack)
{
    // given
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));
    controller.moveBlack(2, 3);

    EXPECT_CALL(*boardMock, putStone(4, 5, Domain::Stone::White));
    controller.moveWhite(4, 5);

    // expect
    EXPECT_CALL(*boardMock, putStone(6, 7, Domain::Stone::Black));

    // when & then
    controller.moveBlack(6, 7);
}


TEST_F(GameControllerTester, testsMakingThirdMoveAsWhite)
{
    // given
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));
    controller.moveBlack(2, 3);

    EXPECT_CALL(*boardMock, putStone(4, 5, Domain::Stone::White));
    controller.moveWhite(4, 5);

    // when & then
    EXPECT_THROW(controller.moveWhite(6, 7), std::runtime_error);
}


TEST_F(GameControllerTester, testsMakingFourthMoveAsBlack)
{
    // given
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));
    controller.moveBlack(2, 3);

    EXPECT_CALL(*boardMock, putStone(4, 5, Domain::Stone::White));
    controller.moveWhite(4, 5);

    EXPECT_CALL(*boardMock, putStone(6, 7, Domain::Stone::Black));
    controller.moveBlack(6, 7);

    // when & then
    EXPECT_THROW(controller.moveBlack(8, 9), std::runtime_error);
}


TEST_F(GameControllerTester, testsMakingFourthMoveAsWhite)
{
    // given
    EXPECT_CALL(*boardMock, putStone(2, 3, Domain::Stone::Black));
    controller.moveBlack(2, 3);

    EXPECT_CALL(*boardMock, putStone(4, 5, Domain::Stone::White));
    controller.moveWhite(4, 5);

    EXPECT_CALL(*boardMock, putStone(6, 7, Domain::Stone::Black));
    controller.moveBlack(6, 7);

    // expect
    EXPECT_CALL(*boardMock, putStone(8, 9, Domain::Stone::White));

    // when & then
    controller.moveWhite(8, 9);
}


} // namespace Testing
} // namespace Application
} // namespace Gomoku
