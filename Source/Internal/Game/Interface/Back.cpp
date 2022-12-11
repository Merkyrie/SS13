# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/Belt.hpp"
# include "Internal/Game/Interface/Back.hpp"

namespace SS13::Game::Interface
{
    __Back::__Back()
    {
        Button.Left(_Belt.Button.Right());
        Button.Up(_Belt.Button.Up());
        Button.Size(_Interface.Size);
    }
    
    void __Back::operator()()
    {
        Button.Draw();
    }
}