# include <iostream>
# include <vector>

# include "External/SDL_image.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Graphics.hpp"

namespace SS13::Engine
{
    __Graphics::__Graphics()
    {
        _Assert("Graphics" , SDL_GetError() , SDL_Init(SDL_INIT_VIDEO) < 0);
        Window = SDL_CreateWindow("Space Station 13" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP);
        _Assert("Graphics" , SDL_GetError() , Window == nullptr);
        Renderer = SDL_CreateRenderer(Window , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        _Assert("Graphics" , SDL_GetError() , Renderer == nullptr);
        _Assert("Graphics" , IMG_GetError() , IMG_Init(IMG_INIT_PNG) == 0);
    }

    void __Graphics::Begin()
    {
        SDL_RenderClear(Renderer);
    }

    signed int __Graphics::LogicalX(signed int X)
    {
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(Window , &Mode);
        return static_cast<signed int>(std::round(static_cast<float>(X) * static_cast<float>(Width) / static_cast<float>(Mode.w)));
    }

    signed int __Graphics::LogicalY(signed int Y)
    {
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(Window , &Mode);
        return static_cast<signed int>(std::round(static_cast<float>(Y) * static_cast<float>(Height) / static_cast<float>(Mode.h)));
    }

    signed int __Graphics::ActualX(signed int X)
    {
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(Window , &Mode);
        return static_cast<signed int>(std::round(static_cast<float>(X) * static_cast<float>(Mode.w) / static_cast<float>(Width)));
    }

    signed int __Graphics::ActualY(signed int Y)
    {
        SDL_DisplayMode Mode;
        SDL_GetWindowDisplayMode(Window , &Mode);
        return static_cast<signed int>(std::round(static_cast<float>(Y) * static_cast<float>(Mode.h) / static_cast<float>(Height)));
    }

    void __Graphics::End()
    {
        SDL_RenderPresent(Renderer);
    }

    __Graphics::~__Graphics()
    {
        IMG_Quit();
        SDL_DestroyRenderer(Renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
    }
}