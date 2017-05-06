#ifndef GOMOKU_APPLICATION_IPLAYER_HPP
#define GOMOKU_APPLICATION_IPLAYER_HPP


namespace Gomoku
{
namespace Application
{


class IPlayer
{
public:
    virtual ~IPlayer() = default;

    virtual void performMove() = 0;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_IPLAYER_HPP
