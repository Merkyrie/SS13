# pragma once

namespace SS13::Game::Interface
{
    inline class __Back
    {
        public:
            Engine::Graphics::_Button Button{"Sprites\\Interface\\Back.png"};
        public:
            __Back();
            void operator()();
    }
    _Back;
}