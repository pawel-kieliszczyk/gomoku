#ifndef GOMOKU_APPLICATION_BOARDWITHUNDO_HPP
#define GOMOKU_APPLICATION_BOARDWITHUNDO_HPP


#include "gomoku/domain/iboard.h"

#include <memory>
#include <stack>
#include <utility>

#include "gomoku/domain/board.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{

class BoardWithUndo : public Domain::IBoard
{
public:
    BoardWithUndo(std::shared_ptr<Domain::IBoard> toCopy);

    int getSize() const override;

    void putStone(int x, int y, const Domain::Stone& stone) override;
    Domain::Stone getStone(int x, int y) const override;
    void removeStone(int x, int y) override;
    int getStonesCount() const override;

    bool hasStone(int x, int y) const override;

    void clear() override;

    void addObserver(Domain::IBoardObserver& observer) override;
    void removeObserver(Domain::IBoardObserver& observer) override;

    void undoMove();

private:
    Domain::Board originalBoard;
    std::stack<std::pair<int, int>> moves;
};


} // namespace ArtificialIntelligence
} // namespace Domain
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_BOARDWITHUNDO_HPP
