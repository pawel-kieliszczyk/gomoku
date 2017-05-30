#ifndef GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICY_HPP
#define GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICY_HPP


#include "gomoku/application/igame_finished_policy.h"

#include <memory>

#include "gomoku/domain/iboard.h"
#include "gomoku/domain/iboard_observer.h"
#include "gomoku/domain/stone.h"


namespace Gomoku
{
namespace Application
{


class GameFinishedWhenFiveInRowPolicy : public IGameFinishedPolicy, public Domain::IBoardObserver
{
public:
    GameFinishedWhenFiveInRowPolicy(std::shared_ptr<Domain::IBoard> board_);
    ~GameFinishedWhenFiveInRowPolicy();
    int getMovesLeft() const;

    bool isFinished() const override;
    std::experimental::optional<Domain::Stone> getWinner() const override;

    void onStonePutAt(int x, int y) override;
    void onBoardCleared() override;

private:
    void checkVertically(int x, int y, const Domain::Stone& stone);
    void checkHorizontally(int x, int y, const Domain::Stone& stone);
    void checkDiagonals(int x, int y, const Domain::Stone& stone);

    void check(int x, int y, const Domain::Stone& stone, int xOffset, int yOffset);

    std::shared_ptr<Domain::IBoard> board;
    int movesLeft;
    bool finished;
    std::experimental::optional<Domain::Stone> winner;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_GAMEFINISHEDWHENFIVEINROWPOLICY_HPP
