# include "Internal/Engine.hpp"

# include "Internal/Game/Interface.hpp"
# include "Internal/Game/Interface/Toggle.hpp"
# include "Internal/Game/Interface/SuitStorage.hpp"
# include "Internal/Game/Interface/ID.hpp"
# include "Internal/Game/Interface/Belt.hpp"
# include "Internal/Game/Interface/Back.hpp"
# include "Internal/Game/Interface/Hands.hpp"

namespace SS13::Game
{
    void __Interface::operator()()
    {
        Interface::_Toggle();
        Interface::_SuitStorage();
        Interface::_ID();
        Interface::_Belt();
        Interface::_Back();
        Interface::_Hands();
    }
}