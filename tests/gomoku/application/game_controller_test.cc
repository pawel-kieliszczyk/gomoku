#include <memory>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "gomoku/application/game_controller.h"

#include "gomoku/mocks/application/game_finished_policy_factory_mock.h"
#include "gomoku/mocks/application/game_finished_policy_mock.h"
#include "gomoku/mocks/application/player_factory_mock.h"
#include "gomoku/mocks/application/player_mock.h"
#include "gomoku/mocks/domain/board_mock.h"


namespace gt = testing;


namespace Gomoku
{
namespace Application
{
namespace Testing
{


MATCHER_P(MatchSharedPtr, expectedSharedPtr, "") { return (arg.get() == expectedSharedPtr.get()); }


struct GameControllerTest : public gt::Test
{
    // mocks:
    std::shared_ptr<Domain::Testing::BoardMock> boardMock =
            std::make_shared<gt::StrictMock<Domain::Testing::BoardMock>>();

    std::shared_ptr<PlayerFactoryMock> playerFactoryMock1 =
            std::make_shared<gt::StrictMock<PlayerFactoryMock>>();

    std::shared_ptr<PlayerFactoryMock> playerFactoryMock2 =
            std::make_shared<gt::StrictMock<PlayerFactoryMock>>();

    std::shared_ptr<GameFinishedPolicyFactoryMock> gameFinishedPolicyFactoryMock =
            std::make_shared<gt::StrictMock<GameFinishedPolicyFactoryMock>>();

    std::shared_ptr<PlayerMock> playerMock1 = std::make_shared<gt::StrictMock<PlayerMock>>();
    std::shared_ptr<PlayerMock> playerMock2 = std::make_shared<gt::StrictMock<PlayerMock>>();
    std::shared_ptr<GameFinishedPolicyMock> gameFinishedPolicyMock = std::make_shared<gt::StrictMock<GameFinishedPolicyMock>>();

    // tested class:
    GameController controller{boardMock, playerFactoryMock1, playerFactoryMock2, gameFinishedPolicyFactoryMock};

    void initializeNewGame()
    {
        // expect
        EXPECT_CALL(*boardMock, clear());
        EXPECT_CALL(*playerFactoryMock1, create(MatchSharedPtr(boardMock), Domain::Stone::Black)).WillOnce(gt::Return(playerMock1));
        EXPECT_CALL(*playerFactoryMock2, create(MatchSharedPtr(boardMock), Domain::Stone::White)).WillOnce(gt::Return(playerMock2));
        EXPECT_CALL(*gameFinishedPolicyFactoryMock, create(MatchSharedPtr(boardMock))).WillOnce(gt::Return(gameFinishedPolicyMock));

        // when & then
        controller.initializeNewGame();
    }
};


TEST_F(GameControllerTest, testsInitializingNewGame)
{
    // when & then
    initializeNewGame();
}


TEST_F(GameControllerTest, testsMakingOneMove)
{
    // given
    initializeNewGame();

    // expect
    EXPECT_CALL(*playerMock1, performMove());
    EXPECT_CALL(*gameFinishedPolicyMock, isFinished()).WillOnce(gt::Return(true));

    // when & then
    controller.play();
}


TEST_F(GameControllerTest, testsMakingTwoMoves)
{
    // given
    initializeNewGame();

    // expect
    EXPECT_CALL(*playerMock1, performMove());
    EXPECT_CALL(*playerMock2, performMove());
    EXPECT_CALL(*gameFinishedPolicyMock, isFinished())
        .Times(2)
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(true));

    // when & then
    controller.play();
}


TEST_F(GameControllerTest, testsMakingThreeMoves)
{
    // given
    initializeNewGame();

    // expect
    EXPECT_CALL(*playerMock1, performMove()).Times(2);
    EXPECT_CALL(*playerMock2, performMove());
    EXPECT_CALL(*gameFinishedPolicyMock, isFinished())
        .Times(3)
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(true));

    // when & then
    controller.play();
}


TEST_F(GameControllerTest, testsMakingFourMoves)
{
    // given
    initializeNewGame();

    // expect
    EXPECT_CALL(*playerMock1, performMove()).Times(2);
    EXPECT_CALL(*playerMock2, performMove()).Times(2);
    EXPECT_CALL(*gameFinishedPolicyMock, isFinished())
        .Times(4)
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(true));

    // when & then
    controller.play();
}


TEST_F(GameControllerTest, testsMakingFiveMoves)
{
    // given
    initializeNewGame();

    // expect
    EXPECT_CALL(*playerMock1, performMove()).Times(3);
    EXPECT_CALL(*playerMock2, performMove()).Times(2);
    EXPECT_CALL(*gameFinishedPolicyMock, isFinished())
        .Times(5)
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(false))
        .WillOnce(gt::Return(true));

    // when & then
    controller.play();
}


} // namespace Testing
} // namespace Application
} // namespace Gomoku
