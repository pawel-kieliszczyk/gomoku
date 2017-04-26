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


int Board::getSize()
{
    return SIZE;
}


void Board::putWhiteDot(int x, int y)
{
    putDot(x, y, BoardValue::WhiteDot);
}


void Board::putBlackDot(int x, int y)
{
    putDot(x, y, BoardValue::BlackDot);
}


BoardValue Board::getValue(int x, int y)
{
    return values[x][y];
}


void Board::clear()
{
    for(int x = 0; x < SIZE; ++x)
        for(int y = 0; y < SIZE; ++y)
            values[x][y] = BoardValue::Blank;
}


void Board::putDot(int x, int y, BoardValue value)
{
    if((x < 0) || (y < 0) || (x >= SIZE) || (y >= SIZE))
        throw std::out_of_range("Putting dots out of the board is forbidden");

    if(values[x][y] != BoardValue::Blank)
        throw std::runtime_error("Putting two dots on the same place is forbidden");

    values[x][y] = value;
}


} // namespace Domain
} // namespace Gomoku
