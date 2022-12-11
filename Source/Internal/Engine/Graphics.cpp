# include <iostream>
# include <vector>

# include "External/SDL_image.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Graphics.hpp"

using namespace std::literals;

namespace SS13::Engine
{
    __Graphics::__Graphics()
    {
        _Assert
        (
            "Failed to initialize video system!"s + "\n" +
            SDL_GetError() + "\n" ,
            SDL_Init(SDL_INIT_VIDEO) < 0
        );
        Window = SDL_CreateWindow("Space Station 13" , 0 , 0 , 0 , 0 , SDL_WINDOW_FULLSCREEN_DESKTOP);
        _Assert
        (
            "Failed to create window!"s + "\n" +
            SDL_GetError() + "\n" ,
            Window == nullptr
        );
        Renderer = SDL_CreateRenderer(Window , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        _Assert
        (
            "Failed to create renderer!"s + "\n" +
            SDL_GetError() + "\n" ,
            Renderer == nullptr
        );
        _Assert
        (
            "Failed to initialize image loader!"s + "\n" +
            SDL_GetError() + "\n" ,
            IMG_Init(IMG_INIT_PNG) == 0
        );
    }

    void __Graphics::Begin()
    {
        SDL_RenderClear(Renderer);
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