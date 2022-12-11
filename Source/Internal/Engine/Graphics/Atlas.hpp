# pragma once

namespace SS13::Engine::Graphics
{
    inline class __Atlas
    {
        public:
            struct _Image
            {
                std::string Path;
                SDL_Texture* Texture;
            };
        public:
            std::vector<_Image> Images;
        public:
            __Atlas();
            SDL_Texture* operator[](const std::string& Path);
    }
    _Atlas;
}