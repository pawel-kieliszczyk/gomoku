#ifndef GOMOKU_INTERFACE_UICONTROLLER_HPP
#define GOMOKU_INTERFACE_UICONTROLLER_HPP


#include <memory>

#include "gomoku/application/iplayer_factory.h"


namespace Gomoku
{
namespace Interface
{


/**
 * Draws console-based UI.
 */
class UIController
{
public:
    void run();

private:
    enum class GameMode {
        PlayerVsPlayer,
        PlayerVsArtificialIntelligence,
        ArtificialIntelligenceVsPlayer
    };

    void printGameTitle();
    GameMode readGameMode();

    std::shared_ptr<Application::IPlayerFactory> getFirstPlayerFactoryFor(GameMode gameMode);
    std::shared_ptr<Application::IPlayerFactory> getSecondPlayerFactoryFor(GameMode gameMode);
};


} // namespace Interface
} // namespace Gomoku


#endif // GOMOKU_INTERFACE_UICONTROLLER_HPP
