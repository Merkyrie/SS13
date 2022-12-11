# include "External/SDL.h"

# include "Internal/Engine/Time.hpp"

namespace SS13::Engine
{
    void __Time::operator()()
    {
        Last = Current;
        Current = SDL_GetTicks64();
    }

    Uint32 __Time::Delta()
    {
        return static_cast<Uint32>(Current - Last);
    }
}