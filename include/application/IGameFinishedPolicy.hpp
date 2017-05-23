#ifndef GOMOKU_APPLICATION_IGAMEFINISHEDPOLICY_HPP
#define GOMOKU_APPLICATION_IGAMEFINISHEDPOLICY_HPP


namespace Gomoku
{
namespace Application
{


class IGameFinishedPolicy
{
public:
    virtual ~IGameFinishedPolicy() = default;

    virtual bool isFinished() const = 0;
};


} // namespace Application
} // namespace Gomoku


#endif // GOMOKU_APPLICATION_IGAMEFINISHEDPOLICY_HPP
