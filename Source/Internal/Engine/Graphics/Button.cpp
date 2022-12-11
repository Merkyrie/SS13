# include <iostream>

# include "External/SDL.h"

# include "Internal/Engine/Graphics/Sprite.hpp"
# include "Internal/Engine/Input/Mouse.hpp"
# include "Internal/Engine/Graphics/Button.hpp"

namespace SS13::Engine::Graphics
{
    bool _Button::Check()
    {
        SDL_Point Point
        {
            .x{Engine::Input::_Mouse.X()} ,
            .y{Engine::Input::_Mouse.Y()} ,
        };
        SDL_Rect Rectangle
        {
            .x{vX} ,
            .y{vY} ,
            .w{vWidth} ,
            .h{vHeight} ,
        };
        return Engine::Input::_Mouse.Pressed(SDL_BUTTON_LEFT) && SDL_PointInRect(&Point , &Rectangle);
    }
}