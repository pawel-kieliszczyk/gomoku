#include "gomoku/application/artificial_intelligence/monte_carlo_tree.h"

#include <cmath>
#include <utility>

#include "gomoku/application/game_finished_when_five_in_row_policy.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


MonteCarloTree::MonteCarloTree(
        std::shared_ptr<Domain::IBoard> board_,
        const Domain::Stone& stoneForNextMove_,
        std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_)
    : board(board_),
      moveCandidatesSelector(moveCandidatesSelector_),
      root(-1, -1, ((stoneForNextMove_ == Domain::Stone::Black) ? Domain::Stone::White : Domain::Stone::Black), nullptr),
      randomGenerator(time(0))
{
}

void MonteCarloTree::runSimulation()
{
    auto boardWithUndo = std::make_shared<BoardWithUndo>(board);
    GameFinishedWhenFiveInRowPolicy gameFinishedPolicy(boardWithUndo);

    Node& leaf = chooseLeafToExpand(boardWithUndo);

    if(gameFinishedPolicy.isFinished())
        return;

    std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(boardWithUndo);

    for(const auto move : possibleMoves)
    {
        leaf.children.push_back(Node(
                move.first,
                move.second,
                ((leaf.stone == Domain::Stone::Black) ? Domain::Stone::White : Domain::Stone::Black),
                &leaf));
        playRandomGameFor(boardWithUndo, leaf.children.back());
    }

    backpropagateWinsAndGames(&leaf);
}


std::pair<int, int> MonteCarloTree::getBestMove()
{
    auto bestMove = std::make_pair(root.children.front().x, root.children.front().y);
    auto bestMoveRating = ratingForMove(root.children.front());

    const auto moves = root.children;
    for(const auto move : moves)
    {
        const auto moveRating = ratingForMove(move);

        if(root.stone == Domain::Stone::Black)
        {
            if(moveRating < bestMoveRating)
            {
                bestMove = std::make_pair(move.x, move.y);
                bestMoveRating = moveRating;
            }
        }
        else
        {
            if(moveRating > bestMoveRating)
            {
                bestMove = std::make_pair(move.x, move.y);
                bestMoveRating = moveRating;
            }
        }
    }

    return bestMove;
}


MonteCarloTree::Node& MonteCarloTree::chooseLeafToExpand(std::shared_ptr<BoardWithUndo> boardWithUndo)
{
    Node* n = &root;

    while(!n->children.empty())
    {
        Node* bestChild = &n->children.front();
        auto bestChildValue = valueForNode(*bestChild);
        for(auto& child : n->children)
        {
            const auto childValue = valueForNode(child);

            if(root.stone == child.stone)
            {
                if(childValue < bestChildValue)
                {
                    bestChild = &child;
                    bestChildValue = childValue;
                }
            }
            else
            {
                if(childValue > bestChildValue)
                {
                    bestChild = &child;
                    bestChildValue = childValue;
                }
            }
        }

        n = bestChild;
        boardWithUndo->putStone(n->x, n->y, n->stone);
    }

    return *n;
}


double MonteCarloTree::valueForNode(const MonteCarloTree::Node& node) const
{
    double value = static_cast<double>(node.numberOfWinsByBlack) / static_cast<double>(node.numberOfGames);
    value += C * std::sqrt(std::log(static_cast<double>(node.parent->numberOfGames)) / static_cast<double>(node.numberOfGames));

    return value;
}


void MonteCarloTree::playRandomGameFor(std::shared_ptr<BoardWithUndo> boardWithUndo, MonteCarloTree::Node& node)
{
    GameFinishedWhenFiveInRowPolicy gameFinishedPolicy(boardWithUndo);
    boardWithUndo->putStone(node.x, node.y, node.stone);

    int movesCount = 1;
    auto stoneForNextMove = ((node.stone == Domain::Stone::Black) ? Domain::Stone::White : Domain::Stone::Black);
    while(!gameFinishedPolicy.isFinished())
    {
        // play random move
        std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(boardWithUndo);

        std::uniform_int_distribution<> dis(0, possibleMoves.size() - 1);
        const auto moveIndex = dis(randomGenerator);
        const auto move = possibleMoves[moveIndex];

        boardWithUndo->putStone(move.first, move.second, stoneForNextMove);

        ++movesCount;
        stoneForNextMove = ((stoneForNextMove == Domain::Stone::Black) ? Domain::Stone::White : Domain::Stone::Black);
    }

    const auto winner = gameFinishedPolicy.getWinner();
    node.numberOfWinsByBlack = ((winner && (*winner == Domain::Stone::Black)) ? 1 : 0);
    node.numberOfGames = 1;

    while(movesCount--)
        boardWithUndo->undoMove();
}


void MonteCarloTree::backpropagateWinsAndGames(MonteCarloTree::Node* node)
{
    int wins = 0;
    int games = 0;

    for(const auto& child : node->children)
    {
        wins += child.numberOfWinsByBlack;
        games += child.numberOfGames;
    }

    while(node != nullptr)
    {
        node->numberOfWinsByBlack += wins;
        node->numberOfGames += games;

        node = node->parent;
    }
}


double MonteCarloTree::ratingForMove(const MonteCarloTree::Node& node)
{
    return static_cast<double>(node.numberOfWinsByBlack) / static_cast<double>(node.numberOfGames);
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
