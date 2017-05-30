#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREE_H
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREE_H


#include <memory>
#include <random>
#include <utility>
#include <vector>

#include "gomoku/application/artificial_intelligence/board_with_undo.h"
#include "gomoku/application/artificial_intelligence/imove_candidates_selector.h"
#include "gomoku/domain/iboard.h"
#include "gomoku/domain/stone.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class MonteCarloTree : public Domain::IBoardObserver
{
public:
    MonteCarloTree(
            std::shared_ptr<Domain::IBoard> board_,
            const Domain::Stone& stoneForNextMove_,
            std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_);
    ~MonteCarloTree();

    void onStonePutAt(int x, int y) override;
    void onBoardCleared() override;

    void runSimulation();
    std::pair<int, int> getBestMove();

private:
    static double constexpr C = 1.41;

    struct Node
    {
        int x;
        int y;
        const Domain::Stone stone;
        int numberOfWinsByBlack{0};
        int numberOfGames{0};

        Node* parent;
        std::vector<std::shared_ptr<Node>> children;

        Node(const int x_, const int y_, const Domain::Stone& stone_, Node* parent_) : x(x_), y(y_), stone(stone_), parent(parent_) {}
    };

    std::shared_ptr<Node> findOrCreateRootChild(const int x, const int y);

    std::shared_ptr<Node> chooseLeafToExpand(std::shared_ptr<BoardWithUndo> boardWithUndo);
    double valueForNode(std::shared_ptr<Node> node) const;
    void playRandomGameFor(std::shared_ptr<BoardWithUndo> boardWithUndo, std::shared_ptr<Node> node);
    void backpropagateWinsAndGames(Node* node);

    double ratingForMove(std::shared_ptr<Node> node);

    std::shared_ptr<Domain::IBoard> board;
    std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector;

    std::shared_ptr<Node> root;

    std::mt19937 randomGenerator;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREE_H
