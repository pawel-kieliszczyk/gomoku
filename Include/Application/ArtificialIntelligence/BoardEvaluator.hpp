#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP


#include <memory>

#include "Domain/IBoard.hpp"
#include "Domain/Stone.hpp"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class BoardEvaluator
{
public:
    static constexpr int FIVE_STONES_WEIGHT = 1000000;
    static constexpr int OPEN_FOUR_STONES_WEIGHT = 1000;
    static constexpr int HALF_OPEN_FOUR_STONES_WEIGHT = 100;
    static constexpr int OPEN_THREE_STONES_WEIGHT = 100;
    static constexpr int OPEN_ONE_TWO_STONES_WEIGHT = 100;
    static constexpr int OPEN_TWO_STONES_WEIGHT = 10;

    static constexpr int OPPONENT_OPEN_FOUR_STONES_WEIGHT = 500000;
    static constexpr int OPPONENT_HALF_OPEN_FOUR_STONES_WEIGHT = 500;
    static constexpr int OPPONENT_OPEN_THREE_STONES_WEIGHT = 500;
    static constexpr int OPPONENT_OPEN_ONE_TWO_STONES_WEIGHT = 500;
    static constexpr int OPPONENT_OPEN_TWO_STONES_WEIGHT = 50;

    int getCurrentEvaluation(std::shared_ptr<Domain::IBoard> board, int lastMoveX, int lastMoveY);

private:
    void initializeBoardCopy(std::shared_ptr<Domain::IBoard> board);
    void saveStoneOnBoardCopy(const int x, const int y, const char stone);
    int countOnBoardCopy(const char* sequence);
    int diagonalBoard1X(const int x, const int y);
    int diagonalBoard2X(const int x, const int y);
    int diagonalBoard1Y(const int x, const int y);
    int diagonalBoard2Y(const int x, const int y);

    // board copy:
    static constexpr int ROWS_COLS_NUM = 15;
    static constexpr int DIAGS_NUM = ROWS_COLS_NUM * 2 - 1;
    static constexpr int BOARD_ENTRY_LENGTH = ROWS_COLS_NUM + 3;

    char horizontalBoard[ROWS_COLS_NUM][BOARD_ENTRY_LENGTH];
    char verticalBoard[ROWS_COLS_NUM][BOARD_ENTRY_LENGTH];
    char diagonalBoard1[DIAGS_NUM][BOARD_ENTRY_LENGTH];
    char diagonalBoard2[DIAGS_NUM][BOARD_ENTRY_LENGTH];
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_BOARDEVALUATOR_HPP
