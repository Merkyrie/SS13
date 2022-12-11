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
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(_Graphics.Window , &Mode);
        signed int X;
        SDL_GetMouseState(&X , nullptr);
        return static_cast<signed int>(std::round(static_cast<float>(X) * static_cast<float>(_Graphics.Width) / static_cast<float>(Mode.w)));
    }

    signed int __Mouse::Y()
    {
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(_Graphics.Window , &Mode);
        signed int Y;
        SDL_GetMouseState(nullptr , &Y);
        return static_cast<signed int>(std::round(static_cast<float>(Y) * static_cast<float>(_Graphics.Height) / static_cast<float>(Mode.h)));
    }
}