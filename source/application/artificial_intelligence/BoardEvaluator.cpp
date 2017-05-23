#include "application/artificial_intelligence/BoardEvaluator.hpp"

#include <cstring>
#include <limits>
#include <utility>
#include <vector>


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


void BoardEvaluator::initializeBoardCopy(std::shared_ptr<Domain::IBoard> board)
{
    for(int i = 0; i < ROWS_COLS_NUM; ++i)
    {
        horizontalBoard[i][0] = '|';

        for(int j = 1; j < BOARD_ENTRY_LENGTH - 2; ++j)
            horizontalBoard[i][j] = '.';

        horizontalBoard[i][BOARD_ENTRY_LENGTH-2] = '|';
        horizontalBoard[i][BOARD_ENTRY_LENGTH-1] = '\0';
    }

    for(int i = 0; i < ROWS_COLS_NUM; ++i)
    {
        verticalBoard[i][0] = '|';

        for(int j = 1; j < BOARD_ENTRY_LENGTH - 2; ++j)
            verticalBoard[i][j] = '.';

        verticalBoard[i][BOARD_ENTRY_LENGTH-2] = '|';
        verticalBoard[i][BOARD_ENTRY_LENGTH-1] = '\0';
    }

    for(int i = 0; i < DIAGS_NUM; ++i)
    {
        const int diagLength = std::min(i + 1, DIAGS_NUM - i) + 3;
        diagonalBoard1[i][0] = '|';

        for(int j = 1; j < diagLength - 2; ++j)
            diagonalBoard1[i][j] = '.';

        diagonalBoard1[i][diagLength-2] = '|';
        diagonalBoard1[i][diagLength-1] = '\0';
    }

    for(int i = 0; i < DIAGS_NUM; ++i)
    {
        const int diagLength = std::min(i + 1, DIAGS_NUM - i) + 3;
        diagonalBoard2[i][0] = '|';

        for(int j = 1; j < diagLength - 2; ++j)
            diagonalBoard2[i][j] = '.';

        diagonalBoard2[i][diagLength-2] = '|';
        diagonalBoard2[i][diagLength-1] = '\0';
    }

    for(int x = 0; x < board->getSize(); ++x)
    {
        for(int y = 0; y < board->getSize(); ++y)
        {
            if(board->hasStone(x, y))
            {
                const auto stone = board->getStone(x, y);
                if(stone == Domain::Stone::Black)
                    saveStoneOnBoardCopy(x, y, 'x');
                else
                    saveStoneOnBoardCopy(x, y, 'o');
            }
        }
    }
}


void BoardEvaluator::saveStoneOnBoardCopy(const int x, const int y, const char stone)
{
    horizontalBoard[x][y+1] = stone;
    verticalBoard[y][x+1] = stone;
    diagonalBoard1[diagonalBoard1X(x, y)][diagonalBoard1Y(x, y)] = stone;
    diagonalBoard2[diagonalBoard2X(x, y)][diagonalBoard2Y(x, y)] = stone;
}


int BoardEvaluator::countOnBoardCopy(const char* sequence)
{
    int counter = 0;
    for(int i = 0; i < ROWS_COLS_NUM; ++i)
    {
        if(strstr(horizontalBoard[i], sequence) != nullptr)
            ++counter;
    }

    for(int i = 0; i < ROWS_COLS_NUM; ++i)
    {
        if(strstr(verticalBoard[i], sequence) != nullptr)
            ++counter;
    }

    for(int i = 0; i < DIAGS_NUM; ++i)
    {
        if(strstr(diagonalBoard1[i], sequence) != nullptr)
            ++counter;
    }

    for(int i = 0; i < DIAGS_NUM; ++i)
    {
        if(strstr(diagonalBoard2[i], sequence) != nullptr)
            ++counter;
    }

    return counter;
}


int BoardEvaluator::diagonalBoard1X(const int x, const int y)
{
    if(y >= x)
        return ROWS_COLS_NUM - (y - x) - 1;

    return ROWS_COLS_NUM + (x - y) - 1;
}


int BoardEvaluator::diagonalBoard2X(const int x, const int y)
{
    return (x + y);
}


int BoardEvaluator::diagonalBoard1Y(const int x, const int y)
{
    if(y >= x)
        return (x + 1);

    return (y + 1);
}


int BoardEvaluator::diagonalBoard2Y(const int x, const int y)
{
    if((x + y) < ROWS_COLS_NUM)
        return (x + 1);

    return (ROWS_COLS_NUM - y);
}


int BoardEvaluator::getCurrentEvaluation(std::shared_ptr<Domain::IBoard> board, int lastMoveX, int lastMoveY)
{
    initializeBoardCopy(board);
    const auto lastMoveStone = board->getStone(lastMoveX, lastMoveY);

    if(lastMoveStone == Domain::Stone::Black)
    {
        int result = 0;
        {
            const int c = countOnBoardCopy("xxxxx");
            if(c > 0)
                return FIVE_STONES_WEIGHT;
        }

        {
            const int c =
                    countOnBoardCopy("oooo.") +
                    countOnBoardCopy(".oooo") +
                    countOnBoardCopy("ooo.o") +
                    countOnBoardCopy("o.ooo") +
                    countOnBoardCopy("oo.oo");

            result += c * (-OPPONENT_OPEN_FOUR_STONES_WEIGHT);
        }

        {
            const int c = countOnBoardCopy(".xxxx.");
            result += c * OPEN_FOUR_STONES_WEIGHT;
        }

        {
            const int c =
                    countOnBoardCopy("oxxxx.") +
                    countOnBoardCopy(".xxxxo") +
                    countOnBoardCopy("|xxxx.") +
                    countOnBoardCopy(".xxxx|") +
                    countOnBoardCopy("oxxx.x") +
                    countOnBoardCopy("x.xxxo") +
                    countOnBoardCopy("|xxx.x") +
                    countOnBoardCopy("x.xxx|") +
                    countOnBoardCopy("oxx.xx") +
                    countOnBoardCopy("xx.xxo") +
                    countOnBoardCopy("|xx.xx") +
                    countOnBoardCopy("xx.xx|") +
                    countOnBoardCopy("ox.xxx") +
                    countOnBoardCopy("xxx.xo") +
                    countOnBoardCopy("|x.xxx") +
                    countOnBoardCopy("xxx.x|");

            result += c * HALF_OPEN_FOUR_STONES_WEIGHT;
        }

        {
            const int c =
                    countOnBoardCopy(".ooo.") +
                    countOnBoardCopy(".o.oo.") +
                    countOnBoardCopy(".oo.o.");

            result += c * (-OPPONENT_OPEN_THREE_STONES_WEIGHT);
        }

        {
            const int c = countOnBoardCopy(".xxx.");
            result += c * OPEN_THREE_STONES_WEIGHT;
        }

        {
            const int c =
                    countOnBoardCopy(".x.xx.") +
                    countOnBoardCopy(".xx.x.");

            result += c * OPEN_ONE_TWO_STONES_WEIGHT;
        }

        {
            const int c =
                    countOnBoardCopy(".oo..") +
                    countOnBoardCopy("..oo.") +
                    countOnBoardCopy(".o.o.");

            result += c * (-OPPONENT_OPEN_TWO_STONES_WEIGHT);
        }

        {
            const int c =
                    countOnBoardCopy("..xx.") +
                    countOnBoardCopy(".xx..") +
                    countOnBoardCopy(".x.x.");

            result += c * OPEN_TWO_STONES_WEIGHT;
        }

        return result;
    }
    else
    {
        int result = 0;
        {
            const int c = countOnBoardCopy("ooooo");
            if(c > 0)
                return -FIVE_STONES_WEIGHT;
        }

        {
            const int c =
                        countOnBoardCopy("xxxx.") +
                        countOnBoardCopy(".xxxx") +
                        countOnBoardCopy("xxx.x") +
                        countOnBoardCopy("x.xxx") +
                        countOnBoardCopy("xx.xx");

            result += c * OPPONENT_OPEN_FOUR_STONES_WEIGHT;
        }

        {
            const int c = countOnBoardCopy(".oooo.");
            result += c * (-OPEN_FOUR_STONES_WEIGHT);
        }

        {
            const int c =
                    countOnBoardCopy("xoooo.") +
                    countOnBoardCopy(".oooox") +
                    countOnBoardCopy("|oooo.") +
                    countOnBoardCopy(".oooo|") +
                    countOnBoardCopy("xooo.o") +
                    countOnBoardCopy("o.ooox") +
                    countOnBoardCopy("|ooo.o") +
                    countOnBoardCopy("o.ooo|") +
                    countOnBoardCopy("xoo.oo") +
                    countOnBoardCopy("oo.oox") +
                    countOnBoardCopy("|oo.oo") +
                    countOnBoardCopy("oo.oo|") +
                    countOnBoardCopy("xo.ooo") +
                    countOnBoardCopy("ooo.ox") +
                    countOnBoardCopy("|o.ooo") +
                    countOnBoardCopy("ooo.o|");

            result += c * (-HALF_OPEN_FOUR_STONES_WEIGHT);
        }

        {
            const int c =
                    countOnBoardCopy(".xxx.") +
                    countOnBoardCopy(".x.xx.") +
                    countOnBoardCopy(".xx.x.");

            result += c * OPPONENT_OPEN_THREE_STONES_WEIGHT;
        }

        {
            const int c = countOnBoardCopy(".ooo.");
            result += c * (-OPEN_THREE_STONES_WEIGHT);
        }

        {
            const int c =
                    countOnBoardCopy(".o.oo.") +
                    countOnBoardCopy(".oo.o.");

            result += c * (-OPEN_ONE_TWO_STONES_WEIGHT);
        }

        {
            const int c =
                    countOnBoardCopy(".xx..") +
                    countOnBoardCopy("..xx.") +
                    countOnBoardCopy(".x.x.");

            result += c * OPPONENT_OPEN_TWO_STONES_WEIGHT;
        }

        {
            const int c =
                    countOnBoardCopy("..oo.") +
                    countOnBoardCopy(".oo..") +
                    countOnBoardCopy(".o.o.");

            result += c * (-OPEN_TWO_STONES_WEIGHT);
        }

        return result;
    }

    return 0;
}


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku
