#include <memory>

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

    // when
    controller.startNewGame();
}


} // namespace Testing
} // namespace Application
} // namespace Gomoku