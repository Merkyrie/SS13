# pragma once

namespace SS13::Engine
{
    inline class __Graphics
    {
        public:
            static constexpr signed int Width{16000};
            static constexpr signed int Height{9000};
        public:
            SDL_Window* Window;
            SDL_Renderer* Renderer;
        public:
            __Graphics();
            void Begin();
            void End();
            ~__Graphics();
    }
    _Graphics;
}