# include <vector>
# include <filesystem>

# include "External/SDL.h"

# include "Internal/Time.hpp"
# include "Internal/Sprite.hpp"
# include "Internal/Animation.hpp"

namespace SS13
{
    _Animation::_Animation(const std::string& Path , signed int Size , Uint32 Duration)
    {
        for (const std::filesystem::directory_entry& Entry : std::filesystem::directory_iterator(Path))
        {
            Sprites.emplace_back(Entry.path().string() , Size);
        }
        this->Size = Size;
        this->Duration = Duration;
        Sprite = 0;
        Delta = 0;
    }

    void _Animation::Reset()
    {
        Sprite = 0;
    }

    void _Animation::Update()
    {
        Delta += Time.Delta;
        if (Delta >= Duration)
        {
            Sprite = (Sprite + Delta / Duration) % Sprites.size();
            Delta = Delta % Duration;
        }
    }

    void _Animation::Draw(signed int X , signed int Y)
    {
        Sprites[Sprite].Draw(X , Y);
    }
}