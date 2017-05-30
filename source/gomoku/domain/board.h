#ifndef GOMOKU_DOMAIN_BOARD_HPP
#define GOMOKU_DOMAIN_BOARD_HPP


#include "gomoku/domain/iboard.h"

#include <experimental/optional>
#include <functional>
#include <vector>


namespace Gomoku
{
namespace Domain
{


class Board : public IBoard
{
public:
    Board();

    int getSize() const override;

    void putStone(int x, int y, const Stone& stone) override;
    Stone getStone(int x, int y) const override;
    void removeStone(int x, int y) override;
    int getStonesCount() const override;

    bool hasStone(int x, int y) const override;

    void clear() override;

    void addObserver(IBoardObserver& observer) override;
    void removeObserver(IBoardObserver& observer) override;

private:
    void notifyObserversAfterStonePut(int x, int y);
    void notifyObserversAfterBoardCleared();

    static const int SIZE = 15;

    std::experimental::optional<Stone> board[SIZE][SIZE];
    int stonesCount{0};

    std::vector<IBoardObserver*> observers;
};


} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_BOARD_HPP
