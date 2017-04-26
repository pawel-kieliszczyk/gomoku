#include "Domain/Board.hpp"

#include <stdexcept>


namespace Gomoku
{
namespace Domain
{


Board::Board()
{
    for(int x = 0; x < SIZE; ++x)
        for(int y = 0; y < SIZE; ++y)
            values[x][y] = Value::Blank;
}


int Board::getSize()
{
    return SIZE;
}


void Board::putWhiteDot(int x, int y)
{
    putDot(x, y, Value::WhiteDot);
}


void Board::putBlackDot(int x, int y)
{
    putDot(x, y, Value::BlackDot);
}


Board::Value Board::getValue(int x, int y)
{
    return values[x][y];
}


void Board::putDot(int x, int y, Value value)
{
    if((x < 0) || (y < 0) || (x >= SIZE) || (y >= SIZE))
        throw std::out_of_range("Putting dots out of the board is forbidden");

    values[x][y] = value;
}


} // namespace Domain
} // namespace Gomoku
