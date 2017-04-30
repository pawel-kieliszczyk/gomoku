#include "Application/ArtificialIntelligence/MiniMaxPlayer.hpp"

#include <algorithm>
#include <iterator>
#include <limits>
#include <set>
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
        const Domain::Stone& stone_)
    : board(board_),
      stone(stone_)
{
}


void MiniMaxPlayer::performMove()
{
    auto boardCopy = std::make_shared<BoardWithUndo>(board);
    std::vector<std::pair<int, int>> validMoves = getValidMoves(boardCopy);

    if(stone == Domain::Stone::Black)
    {
        // maximizing player
        int bestValue = std::numeric_limits<int>::min();
        std::pair<int, int> bestMove = validMoves[0];

        for(const auto& move : validMoves)
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
        std::pair<int, int> bestMove = validMoves[0];

        for(const auto& move : validMoves)
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
        const std::vector<std::pair<int, int>> validMoves = getValidMoves(board);
        for(const auto& move : validMoves)
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
        const std::vector<std::pair<int, int>> validMoves = getValidMoves(board);
        for(const auto& move : validMoves)
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


std::vector<std::pair<int, int>> MiniMaxPlayer::getValidMoves(std::shared_ptr<BoardWithUndo> board)
{
    std::set<std::pair<int, int>> validMoves;

    for(int x = 0; x < board->getSize(); ++x)
    {
        for(int y = 0; y < board->getSize(); ++y)
        {
            if(board->hasStone(x, y))
            {
                insertMoveIfValid(validMoves, board, x-1, y-1);
                insertMoveIfValid(validMoves, board, x-1, y);
                insertMoveIfValid(validMoves, board, x-1, y+1);
                insertMoveIfValid(validMoves, board, x, y-1);
                insertMoveIfValid(validMoves, board, x, y+1);
                insertMoveIfValid(validMoves, board, x+1, y-1);
                insertMoveIfValid(validMoves, board, x+1, y);
                insertMoveIfValid(validMoves, board, x+1, y+1);
            }
        }
    }

    if(validMoves.empty())
        validMoves.insert(std::make_pair(7, 7));

    return std::vector<std::pair<int, int>>(std::begin(validMoves), std::end(validMoves));
}


void MiniMaxPlayer::insertMoveIfValid(
        std::set<std::pair<int, int>>& validMoves,
        std::shared_ptr<BoardWithUndo> board,
        const int x,
        const int y)
{
    if((x < 0) || (x >= board->getSize()))
        return;

    if((y < 0) || (y >= board->getSize()))
        return;

    if(board->hasStone(x, y))
        return;

    validMoves.insert(std::make_pair(x, y));
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
