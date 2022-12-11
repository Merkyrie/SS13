# pragma once

namespace SS13::Game
{
    inline class __Level
    {
        public:
            static constexpr signed int Size{10};
            static constexpr signed int Tile{1000};
        public:
            std::vector<std::vector<Engine::Graphics::_Sprite>> Map{Size , {Size , {"Sprites\\Floor\\Floor.png"}}};
            signed int X{(Engine::_Graphics.Height - Tile) / 2};
            signed int Y{(Engine::_Graphics.Height - Tile) / 2};
        public:
            __Level();
            void operator()();
    }
    _Level;
}