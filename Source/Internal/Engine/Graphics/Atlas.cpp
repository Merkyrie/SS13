# include <iostream>
# include <vector>
# include <filesystem>

# include "External/SDL_image.h"

# include "Internal/Engine/Assert.hpp"
# include "Internal/Engine/Graphics.hpp"
# include "Internal/Engine/Graphics/Sprite.hpp"
# include "Internal/Engine/Graphics/Atlas.hpp"

namespace SS13::Engine::Graphics
{
    __Atlas::__Atlas()
    {
        for (const std::filesystem::directory_entry& Entry : std::filesystem::recursive_directory_iterator{"Sprites"})
        {
            if (Entry.path().extension() == ".png")
            {
                Images.emplace_back(Entry.path().string() , IMG_LoadTexture(_Graphics.Renderer , Entry.path().string().c_str()));
                _Assert("Atlas" , "Failed to load sprite <" + Entry.path().string() + ">!" , Images.back().Texture == nullptr);
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
        _Assert("Atlas" , "Failed to find sprite <" + Path + ">!");
        return nullptr;
    }
}