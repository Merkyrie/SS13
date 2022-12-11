# pragma once

namespace SS13
{
    class _Animation
    {
        public:
            std::vector<_Sprite> Sprites;
            std::vector<_Sprite>::size_type Sprite;
            signed int Size;
            Uint32 Duration;
            Uint32 Delta;
        public:
            _Animation(const std::string& Path , signed int Size , Uint32 Duration);
            void Reset();
            void Update();
            void Draw(signed int X , signed int Y);
    };
}