#ifndef GOMOKU_DOMAIN_BOARD_HPP
#define GOMOKU_DOMAIN_BOARD_HPP


#include "IBoard.hpp"


namespace Gomoku
{
namespace Domain
{


class Board : public IBoard
{
public:
    Board();

    int getSize() override;

    void putWhiteDot(int x, int y) override;
    void putBlackDot(int x, int y) override;

    BoardValue getValue(int x, int y) override;

    void clear() override;

private:
    static const int SIZE = 15;

    void putDot(int x, int y, BoardValue value);

    BoardValue values[SIZE][SIZE];
};


} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_BOARD_HPP
