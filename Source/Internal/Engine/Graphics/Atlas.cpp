# include <iostream>
# include <vector>
# include <filesystem>

# include "External/SDL_image.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Graphics.hpp"
# include "Internal/Engine/Graphics/Sprite.hpp"
# include "Internal/Engine/Graphics/Atlas.hpp"

using namespace std::literals;

namespace SS13::Engine::Graphics
{
    __Atlas::__Atlas()
    {
        for (const std::filesystem::directory_entry& Entry : std::filesystem::recursive_directory_iterator{"Sprites"})
        {
            if (Entry.path().extension() == ".png")
            {
                Images.emplace_back(Entry.path().string() , IMG_LoadTexture(_Graphics.Renderer , Entry.path().string().c_str()));
                _Assert
                (
                    "Failed to load sprite: \""s + Entry.path().string() + "\"!" + "\n" ,
                    Images.back().Texture == nullptr
                );
            }
        }
    }

    SDL_Texture* __Atlas::operator[](const std::string& Path)
    {
        for (const _Image& Image : Images)
        {
            if (Path == Image.Path)
            {
                return Image.Texture;
            }
        }
        _Assert
        (
            "Failed to find sprite: \""s + Path + "\"!" + "\n"
        );
        return nullptr;
    }
}