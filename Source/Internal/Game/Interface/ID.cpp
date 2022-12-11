# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/SuitStorage.hpp"
# include "Internal/Game/Interface/ID.hpp"

namespace SS13::Game::Interface
{
    __ID::__ID()
    {
        Button.Left(_SuitStorage.Button.Right());
        Button.Up(_SuitStorage.Button.Up());
        Button.Size(_Interface.Size);
    }
    
    void __ID::operator()()
    {
        Button.Draw();
    }
}