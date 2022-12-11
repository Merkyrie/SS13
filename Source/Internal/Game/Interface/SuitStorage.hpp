# pragma once

namespace SS13::Game::Interface
{
    inline class __SuitStorage
    {
        public:
            Engine::Graphics::_Button Button{"Sprites\\Interface\\Suit Storage.png"};
        public:
            __SuitStorage();
            void operator()();
    }
    _SuitStorage;
}