# pragma once

namespace SS13::Game::Interface
{
    inline class __Belt
    {
        public:
            Engine::Graphics::_Button Button{"Sprites\\Interface\\Belt.png"};
        public:
            __Belt();
            void operator()();
    }
    _Belt;
}