#ifndef GOMOKU_DOMAIN_IBOARDOBSERVER_HPP
#define GOMOKU_DOMAIN_IBOARDOBSERVER_HPP


namespace Gomoku
{
namespace Domain
{


class IBoardObserver
{
public:
    virtual ~IBoardObserver() = default;

    virtual void onStonePutAt(int x, int y) = 0;
    virtual void onBoardCleared() = 0;
};


} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_DOMAIN_IBOARDOBSERVER_HPP
