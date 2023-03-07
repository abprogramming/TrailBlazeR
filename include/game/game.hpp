#include <game/presentation/gamewindow.hpp>
#include <game/presentation/gamescene.hpp>
#include <game/map/mapmanager.hpp>


namespace trailblazer
{

class Game
{
    presentation::GameWindow_c GameWindow;
    presentation::GameScene_c GameScene;
    map::MapManager_c MapManager;

public:
    void gameLoop()
    {
        GameScene.setMap(MapManager.getNextMap());
        presentation::GameWindow_c::WindowState_e WindowState =
            presentation::GameWindow_c::WindowState_e::OK;
        while (WindowState == presentation::GameWindow_c::WindowState_e::OK)
        {   
            WindowState = GameWindow.updateWindow(&GameScene);
        }
    }

    Game() :
        GameWindow(640, 480, "Test"),
        MapManager("./assets/maps")
    {
        
    }
};

} // namespace trailblazer