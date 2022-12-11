# pragma once

namespace SS13::Game
{
    inline class __Player
    {
        public:
            static constexpr signed int Center{(Engine::_Graphics.Height - _Level.Tile) / 2};
            static constexpr signed int Speed{3};
        public:
            std::vector<std::vector<Engine::Graphics::_Sprite>> Scheme
            {
                {{"Sprites\\Security Officer\\Left.png"} , {"Sprites\\Security Officer\\Up.png"}   , {"Sprites\\Security Officer\\Right.png"}} ,
                {{"Sprites\\Security Officer\\Left.png"} , {"Sprites\\Security Officer\\Down.png"} , {"Sprites\\Security Officer\\Right.png"}} ,
                {{"Sprites\\Security Officer\\Left.png"} , {"Sprites\\Security Officer\\Down.png"} , {"Sprites\\Security Officer\\Right.png"}} ,
            };
            Engine::Graphics::_Sprite* Sprite{&Scheme[1][1]};
            signed int Movement{_Level.Tile};
            signed int X{0};
            signed int Y{0};
        public:
            __Player();
            void operator()();
    }
    _Player;
}