#include "Domain/Board.hpp"

#include <stdexcept>


namespace Gomoku
{
namespace Domain
{


Board::Board()
{
    clear();
}


int Board::getSize() const
{
    return SIZE;
}


void Board::putStone(int x, int y, const Stone& stone)
{
    if((x < 0) || (y < 0) || (x >= SIZE) || (y >= SIZE))
        throw std::out_of_range("Putting stones out of the board is forbidden");

    if(board[x][y])
        throw std::runtime_error("Putting two stones on the same place is forbidden");

    board[x][y] = stone;
}


Stone Board::getStone(int x, int y) const
{
    return *board[x][y];
}


bool Board::hasStone(int x, int y) const
{
    return static_cast<bool>(board[x][y]);
}


void Board::clear()
{
    for(int x = 0; x < SIZE; ++x)
        for(int y = 0; y < SIZE; ++y)
            board[x][y] = std::experimental::optional<Stone>();//.reset();
}


} // namespace Domain
} // namespace Gomoku
