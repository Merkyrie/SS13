# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/Toggle.hpp"
# include "Internal/Game/Interface/SuitStorage.hpp"

namespace SS13::Game::Interface
{
    __SuitStorage::__SuitStorage()
    {
        Button.Left(_Toggle.Shoes.Right());
        Button.Up(_Toggle.Shoes.Up());
        Button.Size(_Interface.Size);
    }
    
    void __SuitStorage::operator()()
    {
        Button.Draw();
    }
}