# pragma once

namespace SS13::Game::Interface
{
    inline class __ID
    {
        public:
            Engine::Graphics::_Button Button{"Sprites\\Interface\\ID.png"};
        public:
            __ID();
            void operator()();
    }
    _ID;
}