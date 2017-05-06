#ifndef GOMOKU_INTERFACE_BOARDDRAWER_HPP
#define GOMOKU_INTERFACE_BOARDDRAWER_HPP


#include "Domain/IBoardObserver.hpp"

#include <memory>

#include "Domain/IBoard.hpp"


namespace Gomoku
{
namespace Interface
{


class BoardDrawer : public Domain::IBoardObserver
{
public:
    BoardDrawer(std::shared_ptr<Domain::IBoard> board_);

    void onStonePutAt(int x, int y) override;
    void onBoardCleared() override;

private:
    void drawCurrentBoard();

    std::shared_ptr<Domain::IBoard> board;
};


} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_INTERFACE_BOARDDRAWER_HPP
