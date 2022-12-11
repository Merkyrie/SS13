# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/ID.hpp"
# include "Internal/Game/Interface/Belt.hpp"

namespace SS13::Game::Interface
{
    __Belt::__Belt()
    {
        Button.Left(_ID.Button.Right());
        Button.Up(_ID.Button.Up());
        Button.Size(_Interface.Size);
    }
    
    void __Belt::operator()()
    {
        Button.Draw();
    }
}