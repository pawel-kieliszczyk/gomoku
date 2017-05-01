#include "Application/ArtificialIntelligence/AlphaBetaPlayer.hpp"

#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

#include "Application/ArtificialIntelligence/BoardWithUndo.hpp"


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

    if(stone == Domain::Stone::Black)
    {
        // maximizing player
        int bestValue = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = possibleMoves[0];

        for(const auto& move : possibleMoves)
        {
            boardCopy->putStone(move.first, move.second, Domain::Stone::Black);
            int v = alphabeta(boardCopy, ALPHA_BETA_DEPTH - 1, alpha, beta, false, move.first, move.second);
            boardCopy->undoMove();

            if(v > bestValue)
            {
                bestValue = v;
                bestMove = move;
            }

            alpha = std::max(alpha, bestValue);
            if(beta <= alpha)
                break;
        }

        board->putStone(bestMove.first, bestMove.second, Domain::Stone::Black);
    }
    else
    {
        // minimizing player
        int bestValue = std::numeric_limits<int>::max();
        std::pair<int, int> bestMove = possibleMoves[0];

        for(const auto& move : possibleMoves)
        {
            boardCopy->putStone(move.first, move.second, Domain::Stone::White);
            int v = alphabeta(boardCopy, ALPHA_BETA_DEPTH - 1, alpha, beta, true, move.first, move.second);
            boardCopy->undoMove();

            if(v < bestValue)
            {
                bestValue = v;
                bestMove = move;
            }

            beta = std::min(beta, bestValue);
            if(beta <= alpha)
                break;
        }

        board->putStone(bestMove.first, bestMove.second, Domain::Stone::White);
    }
}


int AlphaBetaPlayer::alphabeta(
        std::shared_ptr<BoardWithUndo> board,
        const int depth,
        int alpha,
        int beta,
        const bool maximizingPlayer,
        const int lastMoveX,
        const int lastMoveY)
{
    int currentEvaluation = boardEvaluator.evaluate(board, lastMoveX, lastMoveY);
    if((currentEvaluation == -BoardEvaluator::FIVE_STONES_WEIGHT) || (currentEvaluation == BoardEvaluator::FIVE_STONES_WEIGHT))
        return currentEvaluation;

    if(depth == 0)
        return currentEvaluation;

    if(maximizingPlayer)
    {
        int bestValue = std::numeric_limits<int>::min();
        const std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(board);
        for(const auto& move : possibleMoves)
        {
            board->putStone(move.first, move.second, Domain::Stone::Black);
            int v = alphabeta(board, depth - 1, alpha, beta, false, move.first, move.second);
            board->undoMove();

            bestValue = std::max(bestValue, v);
            alpha = std::max(alpha, bestValue);
            if(beta <= alpha)
                break;
        }

        return bestValue;
    }
    else
    {
        int bestValue = std::numeric_limits<int>::max();
        const std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(board);
        for(const auto& move : possibleMoves)
        {
            board->putStone(move.first, move.second, Domain::Stone::White);
            int v = alphabeta(board, depth - 1, alpha, beta, true, move.first, move.second);
            board->undoMove();

            bestValue = std::min(bestValue, v);
            beta = std::min(beta, bestValue);
            if(beta <= alpha)
                break;
        }

        return bestValue;
    }

    return 0;
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
