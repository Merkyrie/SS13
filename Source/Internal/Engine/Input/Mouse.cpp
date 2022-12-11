# include <iostream>

# include "External/SDL.h"

# include "Internal/Engine/Graphics.hpp"
# include "Internal/Engine/Input/Mouse.hpp"

namespace SS13::Engine::Input
{
    void __Mouse::operator()()
    {
        LastState = SDL_GetMouseState(nullptr , nullptr);
    }

    bool __Mouse::Held(Uint32 Button)
    {
        return SDL_GetMouseState(nullptr , nullptr) & SDL_BUTTON(Button);
    }

    bool __Mouse::Pressed(Uint32 Button)
    {
        return !(LastState & SDL_BUTTON(Button)) && (SDL_GetMouseState(nullptr , nullptr) & SDL_BUTTON(Button));
    }

    signed int __Mouse::X()
    {
        signed int X;
        SDL_GetMouseState(&X , nullptr);
        return _Graphics.LogicalX(X);
    }

    signed int __Mouse::Y()
    {
        signed int Y;
        SDL_GetMouseState(nullptr , &Y);
        return _Graphics.LogicalY(Y);
    }
}