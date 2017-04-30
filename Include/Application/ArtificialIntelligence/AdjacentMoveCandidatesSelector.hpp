#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ADJACENTMOVECANDIDATESSELECTOR_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ADJACENTMOVECANDIDATESSELECTOR_HPP


#include "Application/ArtificialIntelligence/IMoveCandidatesSelector.hpp"

#include <set>


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class AdjacentMoveCandidatesSelector : public IMoveCandidatesSelector
{
public:
    std::vector<std::pair<int, int>> selectMoves(std::shared_ptr<Domain::IBoard> board) override;

private:
    void insertMoveIfValid(
            std::set<std::pair<int, int>>& validMoves,
            std::shared_ptr<Domain::IBoard> board,
            const int x,
            const int y);
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_ADJACENTMOVECANDIDATESSELECTOR_HPP
