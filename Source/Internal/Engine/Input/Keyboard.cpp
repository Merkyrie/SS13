# include <iostream>

# include "External/SDL.h"

# include "Internal/Engine/Input/Keyboard.hpp"

namespace SS13::Engine::Input
{
    void __Keyboard::operator()()
    {
        std::copy(SDL_GetKeyboardState(nullptr) , SDL_GetKeyboardState(nullptr) + SDL_NUM_SCANCODES , LastState);
    }
    
    bool __Keyboard::Held(signed int Key)
    {
        return SDL_GetKeyboardState(nullptr)[Key];
    }

    bool __Keyboard::Pressed(signed int Key)
    {
        return !LastState[Key] && SDL_GetKeyboardState(nullptr)[Key];
    }
}