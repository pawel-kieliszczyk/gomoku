namespace Gomoku
{
namespace Domain
{


class Board
{
public:
    enum class Value
    {
        Blank,
        WhiteDot,
        BlackDot
    };

    Board();

    int getSize();

    void putWhiteDot(int x, int y);
    void putBlackDot(int x, int y);

    Value getValue(int x, int y);

private:
    static const int SIZE = 15;

    void putDot(int x, int y, Value value);

    Value values[SIZE][SIZE];
};


} // namespace Domain
} // namespace Gomoku
