#include "Domain/Board.hpp"


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
    values[x][y] = Value::WhiteDot;
}


void Board::putBlackDot(int x, int y)
{
    values[x][y] = Value::BlackDot;
}


Board::Value Board::getValue(int x, int y)
{
    return values[x][y];
}


} // namespace Domain
} // namespace Gomoku
