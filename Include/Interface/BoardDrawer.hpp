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
    void drawCurrentBoard(const int lastMoveX, const int lastMoveY);

    std::string colorNumbers() const;
    std::string colorBoard() const;
    std::string colorBlackStone() const;
    std::string colorWhiteStone() const;
    std::string colorLastMoveBlackStone() const;
    std::string colorLastMoveWhiteStone() const;
    std::string colorDefault() const;

    std::shared_ptr<Domain::IBoard> board;
};


} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_INTERFACE_BOARDDRAWER_HPP
