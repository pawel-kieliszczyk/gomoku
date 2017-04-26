#ifndef GOMOKU_DOMAIN_IBOARD_HPP
#define GOMOKU_DOMAIN_IBOARD_HPP


#include "BoardValue.hpp"


namespace Gomoku
{
namespace Domain
{


class IBoard
{
public:
    virtual ~IBoard() = default;

    virtual int getSize() = 0;

    virtual void putWhiteDot(int x, int y) = 0;
    virtual void putBlackDot(int x, int y) = 0;

    virtual BoardValue getValue(int x, int y) = 0;

    virtual void clear() = 0;
};


} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_IBOARD_HPP
