#include "Application/ArtificialIntelligence/MiniMaxPlayer.hpp"

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


MiniMaxPlayer::MiniMaxPlayer(
        std::shared_ptr<Domain::IBoard> board_,
        const Domain::Stone& stone_,
        std::shared_ptr<IMoveCandidatesSelector> moveCandidatesSelector_)
    : board(board_),
      stone(stone_),
      moveCandidatesSelector(moveCandidatesSelector_)
{
}


void MiniMaxPlayer::performMove()
{
    auto boardCopy = std::make_shared<BoardWithUndo>(board);
    std::vector<std::pair<int, int>> possibleMoves = moveCandidatesSelector->selectMoves(boardCopy);

    if(stone == Domain::Stone::Black)
    {
        // maximizing player
        int bestValue = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = possibleMoves[0];

        for(const auto& move : possibleMoves)
        {
            boardCopy->putStone(move.first, move.second, Domain::Stone::Black);
            int v = minimax(boardCopy, MINIMAX_DEPTH - 1, false);
            boardCopy->undoMove();

            if(v > bestValue)
            {
                bestValue = v;
                bestMove = move;
            }
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
            int v = minimax(boardCopy, MINIMAX_DEPTH - 1, true);
            boardCopy->undoMove();

            if(v < bestValue)
            {
                bestValue = v;
                bestMove = move;
            }
        }

        board->putStone(bestMove.first, bestMove.second, Domain::Stone::White);
    }
}


int MiniMaxPlayer::minimax(std::shared_ptr<BoardWithUndo> board, int depth, bool maximizingPlayer)
{
    int currentEvaluation = boardEvaluator.evaluate(board);
    if((currentEvaluation == std::numeric_limits<int>::min()) || (currentEvaluation == std::numeric_limits<int>::max()))
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
            int v = minimax(board, depth - 1, false);
            board->undoMove();

            bestValue = std::max(bestValue, v);
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
            int v = minimax(board, depth - 1, true);
            board->undoMove();

            bestValue = std::min(bestValue, v);
        }

        return bestValue;
    }

    return 0;
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
