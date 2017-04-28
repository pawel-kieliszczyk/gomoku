#ifndef GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICY_HPP
#define GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICY_HPP


#include "IGameFinishedPolicy.hpp"

#include <memory>

#include "Domain/IBoard.hpp"
#include "Domain/IBoardObserver.hpp"
#include "Domain/Stone.hpp"


namespace Gomoku
{
namespace Application
{


class GameFinishedWhenFiveInRowPolicy : public IGameFinishedPolicy, public Domain::IBoardObserver
{
public:
    GameFinishedWhenFiveInRowPolicy(std::shared_ptr<Domain::IBoard> board_);

    bool isFinished() const override;

    void onStonePutAt(int x, int y) override;

private:
    void checkVertically(int x, int y, const Domain::Stone& stone);
    void checkHorizontally(int x, int y, const Domain::Stone& stone);
    void checkDiagonals(int x, int y, const Domain::Stone& stone);

    void check(int x, int y, const Domain::Stone& stone, int xOffset, int yOffset);

    std::shared_ptr<Domain::IBoard> board;
    bool finished;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICY_HPP
