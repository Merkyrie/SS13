# pragma once

namespace SS13::Game::Interface
{
    inline class __Hands
    {
        public:
            float Scale{std::round(static_cast<float>(_Interface.Size) / 40.0f)};
            bool Right{true};
            Engine::Graphics::_Sprite Frame{"Sprites\\Interface\\Hands\\Frame.png"};
            Engine::Graphics::_Button Equip{"Sprites\\Interface\\Hands\\Equip.png"};
            Engine::Graphics::_Button Swap{"Sprites\\Interface\\Hands\\Swap.png"};
            Engine::Graphics::_Button LeftHand{"Sprites\\Interface\\Hands\\Left Hand.png"};
            Engine::Graphics::_Button RightHand{"Sprites\\Interface\\Hands\\Right Hand.png"};
            Engine::Graphics::_Sprite Selection{"Sprites\\Interface\\Hands\\Selection.png"};
        public:
            __Hands();
            void operator()();
    }
    _Hands;
}