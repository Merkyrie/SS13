# include <iostream>

# include "External/SDL.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Input/Keyboard.hpp"
# include "Internal/Engine/Input/Mouse.hpp"
# include "Internal/Engine/Input.hpp"

namespace SS13::Engine
{
    void __Input::operator()()
    {
        Input::_Keyboard();
        Input::_Mouse();
        SDL_PumpEvents();
    }
}