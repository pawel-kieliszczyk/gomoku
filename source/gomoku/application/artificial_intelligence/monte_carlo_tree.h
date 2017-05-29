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


class MonteCarloTree
{
public:
    MonteCarloTree(
            std::shared_ptr<Domain::IBoard> board_,
            const Domain::Stone& stoneForNextMove_,
            std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_);

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
        std::vector<Node> children;

        Node(int x_, int y_, const Domain::Stone& stone_, Node* parent_) : x(x_), y(y_), stone(stone_), parent(parent_) {}
    };

    Node& chooseLeafToExpand(std::shared_ptr<BoardWithUndo> boardWithUndo);
    double valueForNode(const Node& node) const;
    void playRandomGameFor(std::shared_ptr<BoardWithUndo> boardWithUndo, Node& node);
    void backpropagateWinsAndGames(Node* node);

    double ratingForMove(const Node& node);

    std::shared_ptr<Domain::IBoard> board;
    std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector;

    Node root;

    std::mt19937 randomGenerator;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_MONTECARLOTREE_H
