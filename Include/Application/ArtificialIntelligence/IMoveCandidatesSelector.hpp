#ifndef GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_IMOVECANDIDATESSELECTOR_HPP
#define GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_IMOVECANDIDATESSELECTOR_HPP


#include <memory>
#include <utility>
#include <vector>

#include "Domain/IBoard.hpp"


namespace Gomoku
{
namespace Application
{
namespace ArtificialIntelligence
{


class IMoveCandidatesSelector
{
public:
    virtual ~IMoveCandidatesSelector() = default;

    virtual std::vector<std::pair<int, int>> selectMoves(std::shared_ptr<Domain::IBoard> board) = 0;
};


} // namespace ArtificialIntelligence
} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_ARTIFICIALINTELLIGENCE_IMOVECANDIDATESSELECTOR_HPP
