#ifndef GOMOKU_DOMAIN_IBOARD_HPP
#define GOMOKU_DOMAIN_IBOARD_HPP


#include "Stone.hpp"


namespace Gomoku
{
namespace Domain
{


class IBoard
{
public:
    virtual ~IBoard() = default;

    virtual int getSize() const = 0;

    virtual void putStone(int x, int y, const Stone& stone) = 0;
    virtual Stone getStone(int x, int y) const = 0;
    virtual bool hasStone(int x, int y) const = 0;

    virtual void clear() = 0;
};


} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_IBOARD_HPP
