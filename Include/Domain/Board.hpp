#ifndef GOMOKU_DOMAIN_BOARD_HPP
#define GOMOKU_DOMAIN_BOARD_HPP


#include "IBoard.hpp"

#include <experimental/optional>


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
    bool hasStone(int x, int y) const override;

    void clear() override;

private:
    static const int SIZE = 15;

    std::experimental::optional<Stone> board[SIZE][SIZE];
};


} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_BOARD_HPP
