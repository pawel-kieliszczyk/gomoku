#include "gomoku/application/artificial_intelligence/alpha_beta_player.h"

#include <algorithm>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

#include "gomoku/application/artificial_intelligence/board_with_undo.h"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


AlphaBetaPlayer::AlphaBetaPlayer(
        std::shared_ptr<Domain::IBoard> board_,
        const Domain::Stone& stone_,
        std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_)
    : board(board_),
      stone(stone_),
      moveCandidatesSelector(moveCandidatesSelector_)
{
}


void AlphaBetaPlayer::performMove()
{
    auto boardCopy = std::make_shared<BoardWithUndo>(board);
    std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(boardCopy);

    int alpha = std::numeric_limits<int>::min();
    int beta = std::numeric_limits<int>::max();

    rankAndLimitMoves(boardCopy, possibleMoves, stone);

    if(stone == Domain::Stone::Black)
    {
        // maximizing player
        AlphaBetaRank bestValue(std::numeric_limits<int>::min(), 0);
        std::pair<int, int> bestMove = possibleMoves[0];

        for(const auto& move : possibleMoves)
        {
            boardCopy->putStone(move.first, move.second, Domain::Stone::Black);
            const AlphaBetaRank v = alphabeta(boardCopy, ALPHA_BETA_DEPTH - 1, alpha, beta, false, move.first, move.second);
            boardCopy->undoMove();


            if(bestValue.value < v.value)
            {
                bestValue = v;
                bestMove = move;
            }
            else if((bestValue.value == v.value) && (bestValue.valueReachedAtDepth < v.valueReachedAtDepth))
            {
                bestValue = v;
                bestMove = move;
            }

            alpha = std::max(alpha, bestValue.value);
            if(beta <= alpha)
                break;
        }

        board->putStone(bestMove.first, bestMove.second, Domain::Stone::Black);
    }
    else
    {
        // minimizing player
        AlphaBetaRank bestValue(std::numeric_limits<int>::max(), 0);
        std::pair<int, int> bestMove = possibleMoves[0];

        for(const auto& move : possibleMoves)
        {
            boardCopy->putStone(move.first, move.second, Domain::Stone::White);
            const AlphaBetaRank v = alphabeta(boardCopy, ALPHA_BETA_DEPTH - 1, alpha, beta, true, move.first, move.second);
            boardCopy->undoMove();

            if(bestValue.value > v.value)
            {
                bestValue = v;
                bestMove = move;
            }
            else if((bestValue.value == v.value) && (bestValue.valueReachedAtDepth < v.valueReachedAtDepth))
            {
                bestValue = v;
                bestMove = move;
            }

            beta = std::min(beta, bestValue.value);
            if(beta <= alpha)
                break;
        }

        board->putStone(bestMove.first, bestMove.second, Domain::Stone::White);
    }
}


AlphaBetaPlayer::AlphaBetaRank AlphaBetaPlayer::alphabeta(
        std::shared_ptr<BoardWithUndo> board,
        const int depth,
        int alpha,
        int beta,
        const bool maximizingPlayer,
        const int lastMoveX,
        const int lastMoveY)
{
    int currentEvaluation = boardEvaluator.getCurrentEvaluation(board, lastMoveX, lastMoveY);
    if((currentEvaluation == -BoardEvaluator::FIVE_STONES_WEIGHT) || (currentEvaluation == BoardEvaluator::FIVE_STONES_WEIGHT))
        return AlphaBetaRank(currentEvaluation, depth);

    if(depth == 0)
        return AlphaBetaRank(currentEvaluation, depth);

    if(maximizingPlayer)
    {
        AlphaBetaRank bestValue(std::numeric_limits<int>::min(), 0);
        std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(board);

        rankAndLimitMoves(board, possibleMoves, Domain::Stone::Black);

        for(const auto& move : possibleMoves)
        {
            board->putStone(move.first, move.second, Domain::Stone::Black);
            const auto v = alphabeta(board, depth - 1, alpha, beta, false, move.first, move.second);
            board->undoMove();

            if(bestValue.value < v.value)
                bestValue = v;
            else if((bestValue.value == v.value) && (bestValue.valueReachedAtDepth < v.valueReachedAtDepth))
                bestValue = v;

            alpha = std::max(alpha, bestValue.value);
            if(beta <= alpha)
                break;
        }

        return bestValue;
    }
    else
    {
        AlphaBetaRank bestValue(std::numeric_limits<int>::max(), 0);
        std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(board);

        rankAndLimitMoves(board, possibleMoves, Domain::Stone::White);

        for(const auto& move : possibleMoves)
        {
            board->putStone(move.first, move.second, Domain::Stone::White);
            const AlphaBetaRank v = alphabeta(board, depth - 1, alpha, beta, true, move.first, move.second);
            board->undoMove();

            if(bestValue.value > v.value)
                bestValue = v;
            else if((bestValue.value == v.value) && (bestValue.valueReachedAtDepth < v.valueReachedAtDepth))
                bestValue = v;

            beta = std::min(beta, bestValue.value);
            if(beta <= alpha)
                break;
        }

        return bestValue;
    }

    return AlphaBetaRank(0, 0);
}


void AlphaBetaPlayer::rankAndLimitMoves(
        std::shared_ptr<BoardWithUndo> board,
        std::vector<std::pair<int, int>>& moves,
        const Domain::Stone& stone)
{
    if(moves.size() <= RANKED_MOVES_LIMIT)
        return;

    std::vector<std::tuple<int, int, int>> rankedMoves;

    for(const auto& move : moves)
    {
        board->putStone(move.first, move.second, stone);
        const int v = boardEvaluator.getCurrentEvaluation(board, move.first, move.second);
        board->undoMove();

        rankedMoves.push_back(std::make_tuple(v, move.first, move.second));
    }

    std::sort(std::begin(rankedMoves), std::end(rankedMoves));

    moves.clear();
    if(stone == Domain::Stone::Black)
    {
        for(int i = 1; i <= RANKED_MOVES_LIMIT; ++i)
        {
            auto rm = rankedMoves[rankedMoves.size()-i];
            moves.emplace_back(std::get<1>(rm), std::get<2>(rm));
        }
    }
    else
    {
        for(int i = 0; i < RANKED_MOVES_LIMIT; ++i)
        {
            auto rm = rankedMoves[i];
            moves.emplace_back(std::get<1>(rm), std::get<2>(rm));
        }
    }
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
