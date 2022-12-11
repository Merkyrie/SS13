# include "Internal/Engine.hpp"

# include "Internal/Game/Level.hpp"
# include "Internal/Game/Player.hpp"
# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/Toggle.hpp"
# include "Internal/Game/Interface/SuitStorage.hpp"
# include "Internal/Game/Interface/ID.hpp"
# include "Internal/Game/Interface/Belt.hpp"
# include "Internal/Game/Interface/Back.hpp"
# include "Internal/Game/Interface/Hands.hpp"

using namespace SS13;

signed int main(signed int , char**)
{
    while (!Engine::Input::_Keyboard.Held(SDL_SCANCODE_ESCAPE))
    {
        Engine::_Graphics.Begin();
        Engine::_Time();
        Engine::_Input();
        Game::_Level();
        Game::_Player();
        Game::_Interface();
        Engine::_Graphics.End();
    }
    return 0;
}